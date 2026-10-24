// ===============================
// SMOOTH SCROLL
// ===============================

document.querySelectorAll(".nav-links a").forEach(link => {

    link.addEventListener("click", function (e) {

        const targetId = this.getAttribute("href");

        // जर href # ने सुरू होत असेल तर smooth scroll
        if (targetId.startsWith("#")) {

            e.preventDefault();

            const section = document.querySelector(targetId);

            if (section) {
                section.scrollIntoView({
                    behavior: "smooth"
                });
            }
        }

    });

});


// ===============================
// ACTIVE NAVIGATION LINK
// ===============================

const sections = document.querySelectorAll("section");
const navLinks = document.querySelectorAll(".nav-links a");

window.addEventListener("scroll", () => {

    let current = "";

    sections.forEach(section => {

        const sectionTop = section.offsetTop - 150;
        const sectionHeight = section.offsetHeight;

        if (
            window.scrollY >= sectionTop &&
            window.scrollY < sectionTop + sectionHeight
        ) {
            current = section.getAttribute("id");
        }

    });

    navLinks.forEach(link => {

        link.classList.remove("active");

        if (link.getAttribute("href") === "#" + current) {
            link.classList.add("active");
        }

    });

});


// ===============================
// PROJECT CARD CLICK EFFECT
// ===============================

const projectCards = document.querySelectorAll(".project-card");

projectCards.forEach(card => {

    card.addEventListener("mouseenter", () => {
        card.style.cursor = "pointer";
    });

});


// ===============================
// PAGE LOADED MESSAGE
// ===============================

console.log("Portfolio Website Loaded Successfully!");