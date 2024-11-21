const form = document.getElementById('form')
const errorElement = document.getElementById('error')

function isContainCapital(s){
    let contain = false
    s.split('').forEach((c) => {
        if(c >= 'A' && c <= 'Z'){
            contain = true
        }
    })

    return contain
}

function isContainNumeric(s){
    let contain = false
    s.split('').forEach((c) => {
        if(c >= '0' && c <= '9'){
            contain = true
        }
    })

    return contain
}

function isContainLowercase(s){
    let contain = false
    s.split('').forEach((c) => {
        if(c >= 'a' && c <= 'z'){
            contain = true
        }
    })

    return contain
}

const handleFormEvent = (event) => {
    event.preventDefault()
    console.log(event);

    const firstnameElement = document.getElementById('first-name')
    const lastnameElement = document.getElementById('last-name')
    const boxElement = document.getElementById('box')
    const addressElement = document.getElementById('address')
    const emailElement = document.getElementById('email')
    const passwordElement = document.getElementById('password')
    
    if(
        firstnameElement.value == ' ' ||
        lastnameElement.value == ' '
    ) {
        errorElement.value = 'Every field is required :)'
        return
    }

    const splittedFUllName = fullNameElement.innerHTML.split(' ')

    if(splittedFUllName.length < 2) {
        errorElement.innerHTML = 'Name must at least contain 2 words'
        return
    }

    if(
        addressElement.value == ' '
    ) {
        errorElement.value = 'Every field is required'
        return
    }

    console.log(boxElement)

    const keongIndex = emailElement.value.indexOf('@')
    const dotIndex = emailElement.value.indexOf('.')

    if(keongIndex == -1){
        errorElement.innerHTML = 'Email must contain @'
        return
    }

    if(dotIndex == -1){
        errorElement.innerHTML = 'Email must contain .'
        return
    }

    if(dotIndex > keongIndex) {
        errorElement.innerHTML = '. must be after @'
        return
    }

    if(confirmpasswordElement.value != passwordElement.value) {
        errorElement.innerHTML = 'password not same with confirm password'
        return
    }

    if(
        !isContainCapital(passwordElement.value) || 
        !isContainLowercase(passwordElement.value) || 
        !isContainNumeric(passwordElement.value) 
    ) {
        errorElement.innerHTML = 'password must contain at least one lowercase uppercase and numeric'
        return 
    }

    errorElement.innerHTML = ''
    form.addEventListener('submit', handleFormEvent);
}
