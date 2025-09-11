function password_check() {
    var password_1 = document.getElementById("password_1").value;
    var password_2 = document.getElementById("password_2").value;

    if (password_1.length < 8) {
        alert("Your first password must be 8 characters or more.")

    } else if (password_2.length < 8) {
        alert("Your second password must be 8 characters or more.")

    } else if (password_1 != password_2) {
        alert("Please ensure your passwords are the same.")

    } else {
        alert("Your passwords are validated.")
    }
}