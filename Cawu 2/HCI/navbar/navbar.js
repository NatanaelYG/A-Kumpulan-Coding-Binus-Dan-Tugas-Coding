const userclick = document.getElementById('user-click');
const subMenu = document.getElementById('acc-menu');

let isSubMenuOpen = false;

userclick.addEventListener('click', () => {
    if (!isSubMenuOpen) {
        subMenu.style.transition = '1s';
        subMenu.style.height = '150px';
    } else {
        subMenu.style.transition = '0.5s';
        subMenu.style.height = '0';
    }
    isSubMenuOpen = !isSubMenuOpen;
});