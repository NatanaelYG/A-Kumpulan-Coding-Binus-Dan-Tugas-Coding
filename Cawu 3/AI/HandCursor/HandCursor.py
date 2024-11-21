import cv2
import mediapipe
import pyautogui

# Initialize Mediapipe Hands and DrawingUtils
capture_hands = mediapipe.solutions.hands.Hands()
drawing_option = mediapipe.solutions.drawing_utils

# Initialize Camera
camera = cv2.VideoCapture(0)
screen_width, screen_height = pyautogui.size()

# Initialize previous hand coordinates
x1 = y1 = x2 = y2 = 0

while True:
    _, image = camera.read()
    image_height, image_width, _ = image.shape
    image = cv2.flip(image, 1)
    
    # Convert image to RGB for Mediapipe processing
    rgb_image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    output_hands = capture_hands.process(rgb_image)
    all_hands = output_hands.multi_hand_landmarks
    
    if all_hands:
        for hand in all_hands:
            drawing_option.draw_landmarks(image, hand)
            one_hand_landmarks = hand.landmark
            
            for id, lm in enumerate(one_hand_landmarks):
                x = int(lm.x * image_width)
                y = int(lm.y * image_height)
                
                if id == 8:  # Index finger tip
                    mouse_x = int(screen_width / image_width * x)
                    mouse_y = int(screen_height / image_height * y)
                    cv2.circle(image, (x, y), 10, (0, 255, 255), -1)
                    pyautogui.moveTo(mouse_x, mouse_y)
                    x1, y1 = x, y
                
                if id == 4:  # Thumb tip
                    x2, y2 = x, y
                    cv2.circle(image, (x, y), 10, (0, 255, 255), -1)
        
        if x1 != 0 and y1 != 0 and x2 != 0 and y2 != 0:  # Check if coordinates are initialized
            dist = ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5  # Euclidean distance
            if dist < 40:
                pyautogui.click()

    # Display the image
    cv2.imshow("Hand Movement Video Capture", image)
    key = cv2.waitKey(1)
    if key == 27:  # Exit on 'Esc' key
        break

# Release resources
camera.release()
cv2.destroyAllWindows()
