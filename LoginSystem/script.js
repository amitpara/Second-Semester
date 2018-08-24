function formValidator(){
	var flag=0;
	var fname = document.getElementById('fname').value;
	var lname = document.getElementById('lname').value;
	var username = document.getElementById('username').value;
	var email = document.getElementById('email').value;
	var pass = document.getElementById('pass').value;
	var rePass = document.getElementById('rePass').value;

	var fnameError = document.getElementById('fnameError');
	var lnameError = document.getElementById('lnameError');
	var userError = document.getElementById('userError');
	var emailError = document.getElementById('emailError');
	var passError = document.getElementById('passError');
	var rePassError = document.getElementById('rePassError');

	var regEmail = /^(([^<>()\[\]\.,;:\s@\"]+(\.[^<>()\[\]\.,;:\s@\"]+)*)|(\".+\"))@(([^<>()[\]\.,;:\s@\"]+\.)+[^<>()[\]\.,;:\s@\"]{2,})$/i;
	var regName = /^[a-zA-Z ]{2,30}$/;
	var regUsername = /\w+/g;

	if (fname == "") {
		fnameError.textContent = "First Name can't be empty.";
		flag++;
	}else if (!regName.test(fname)){
		fnameError.textContent = "Enter a valid first name.";
		flag++;
	}else {
		fnameError.textContent = "";
	}
	if (lname == ""){
		lnameError.textContent = "Last Name can't be empty.";
		flag++;
	}else if (!regName.test(lname)){
		lnameError.textContent = "Enter a valid last name.";
		flag++;
	}else {
		lnameError.textContent = "";
	}
	if (username == ""){
		userError.textContent = "Username can't be empty.";
		flag++;
	}else if (!regUsername.test(email)){
		userError.textContent = "Enter 2-10 valid characters(numbers, letters, _ ) only.";
		flag++;
	}else{
		userError.textContent = "";
	}
	if (email == "") {
		emailError.textContent = "Email can't be empty.";
		flag++;
	}else if (!regEmail.test(email)){
		emailError.textContent = "Enter a valid email address.";
		flag++;
		}else{
		emailError.textContent = "";
	}
	if (pass == ""){
		passError.textContent = "Password can't be empty.";
		flag++;
	} else {
		passError.textContent = "";
	}
	if (rePass != pass){
			rePassError.textContent = "Password did not match.";
			flag++;
		} else{
			rePassError.textContent = "";
		}
	if (flag == 0) {
		return true;
	}
	return false;
}

function showPassword(){
				var show = document.getElementById('pass');
				var rePass = document.getElementById('rePass');
				if (show.type == "password") {
					show.type = "text";
					rePass.type = "text";
				}else {
					show.type = "password";
					rePass.type = "password";
				}
			}
