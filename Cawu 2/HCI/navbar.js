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

// const viewMoreBtn = document.getElementById('view-more-btn');
// const hiddenSections = document.getElementById('hidden-sections');

// let isHidden = true;

// viewMoreBtn.addEventListener('click', () => {
//     if (isHidden) {
//         hiddenSections.style.display = 'block';
//         hiddenSections.style.transition = '1s'
//         // Scroll to the hidden sections
//         hiddenSections.scrollIntoView({ behavior: 'smooth' });
//         // viewMoreBtn.style.display = 'none';
//     } else {
//         hiddenSections.style.transition = '0.5s'
//         hiddenSections.style.display = 'none';
//     }
//     isHidden = !isHidden;
// });

document.addEventListener("DOMContentLoaded", function() {
    const viewMoreBtn = document.getElementById('view-more-btn');
    const hiddenSections = document.getElementById('hidden-sections');
    const items = document.querySelectorAll('.items')[0]; // Memilih elemen pertama dari querySelectorAll

    let isHidden = true;

    // Sembunyikan daftar film saat halaman dimuat
    hiddenSections.style.display = 'none';

    // Tampilkan daftar film dan tombol "View More" saat tombol "View More" diklik
    viewMoreBtn.addEventListener('click', () => {
        if (isHidden) {
            hiddenSections.style.display = 'block'; // Tampilkan daftar film
            viewMoreBtn.style.display = 'none'; // Sembunyikan tombol "View More"
            items.style.display = 'flex'; // Tampilkan daftar film
            isHidden = false;
        }
    });
});

