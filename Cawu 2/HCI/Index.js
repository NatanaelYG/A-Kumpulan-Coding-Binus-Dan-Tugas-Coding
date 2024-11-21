// let age  = 2

// console.log(age)

// age = "jadi string"

// console.log(age)

// let listNama = []

// listNama.push('Bang')
// listNama.push('Joko')
// listNama.push('Fred')
// listNama.sort()
// listNama.length



// console.log(listNama)

// listNama.pop()

// for (let index = 0; index < 6; index++) {
//     console.log('Hahlsakdas')
// }

// if(listNama.length < 5){
//     console.log('panjang array list nama lebih kecil dari 5')
// }

// let i = 0

// while(i < 10){
//     console.log('Hansen ha')
//     i++
// }

// listNama.forEach((name, i) => {
//     console.log(i + ". " + name)
// })

// listNama.map((name, i) => {
//     console.log(i + ". " + name)
// })

// function updateDate(){
//     const textElement = document.getElementById('text')
//     textElement.innerHTML = new Date()
// }

// const buttonElement = document.getElementById('id')
// console.log(buttonElement)

// document.onload

// buttonElement.addEventListener('Click', updateDate)


window.addEventListener('keydown', (e) => {
    const key = e.key
    console.log(key)
    const textElement = document.getElementById('textToCheck')
    const inputP = document.getElementById('id')

    if(key == 'Backspace'){
            inputP.innerHTML = inputP.innerHTML.slice(0, -1)
    } else if(key == 'Enter'){
        if(textElement.innerHTML == inputP.innerHTML){
            alert("you win")
        }
    } else {
        inputP.innerHTML = inputP.innerHTML + key
    }
})