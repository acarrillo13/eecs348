function password_check() {
    var pass1 = document.getElementById("pass1").value;
    var pass2 = document.getElementById("pass2").value;


    if (pass1.length < 8) {
        alert("First password isn't long enough")
    } else if (pass2.length < 8) {
        alert("Second password isn't long enough")
    } else if (pass1 != pass2) {
        alert("The passwords don't match")
    } else {
        alert("Password validated")
    }
}
