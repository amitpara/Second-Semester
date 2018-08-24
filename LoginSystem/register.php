<?php
	session_start();
	if (isset($_SESSION['loggedin']) && ($_SESSION['loggedin'] == 'yes')) {
	 	header('location: index.php');
	 } 
?>
<!DOCTYPE html>
<html>
	<head>
		<title>Registration</title>
	</head>
	<body>
		<form action="register.php" method="post" onsubmit="return formValidator()">
			<fieldset>
				<legend>Enter your information:</legend>
				<table>
					<tr>
						<td align="right"> First Name : </td>
						<td>
							<label>
								<input type="text" name="fname" id="fname" value="<?php echo isset($_POST["fname"]) ? $_POST["fname"] : ''; ?>">
							</label>
						</td>
							<td> <span style="color: red;" id="fnameError"> </span></td>
					</tr>
					<tr>
						<td align="right"> Last Name : </td>
						<td>
							<label>
								<input type="text" name="lname" id="lname" value="<?php echo isset($_POST["lname"]) ? $_POST["lname"] : ''; ?>">
							</label>
						</td>
						<td> <span style="color: red;" id="lnameError"></span></td>
					</tr>
						<tr>
						<td align="right"> Username : </td>
						<td>
							<label>
								<input type="text" name="username" id="username" value="<?php echo isset($_POST["username"]) ? $_POST["username"] : ''; ?>">
							</label>
						</td>
						<td> <span style="color: red;" id="userError";></span></td>
					</tr>
					<tr>
						<td align="right"> Email : </td>
						<td>
							<label>
								<input type="email" name="email" id="email" value="<?php echo isset($_POST["email"]) ? $_POST["email"] : ''; ?>">
							</label>
						</td>
						<td> <span style="color: red;" id="emailError"></span></td>
					</tr>
					<tr>
						<td align="right"> Password : </td>
						<td>
							<label>
								<input type="password" name="password" id="pass" minlength="8" maxlength="32">
							</label>
						</td>
						<td> <span style="color: red;" id="passError"></span></td>
					</tr>
					<tr>
						<td align="right"> Confirm Password : </td>
						<td>
							<label>
								<input type="password" name="rePassword" id="rePass">
							</label>
						</td>
						<td> <span style="color: red;" id="rePassError"></span> </td>
					</tr>
					<tr>
						<td colspan="2" align="right">
							<label>
								<input type="checkbox" name="checkbox" onclick="showPassword()"> Show Password
							</label>
						</td>
					</tr>
					<tr>
						<td colspan="2" align="right">
							<label>
								<input type="submit" name="submit" value="Register">
							</label>
						</td>
					</tr>
				</table>
				Already Registered? <a href="login.php">Login Here. </a>
			</fieldset>
		</form>
		<script type="text/javascript" src="script.js"></script>

		<?php
			if (isset($_POST['submit'])) {
		
			$host = "localhost";
			$username = "root";
			$password = "";
			$database = "loginsystem";

			$connection = mysqli_connect($host, $username , $password, $database);
			if (!$connection) {
				die ('Database connection failed.');
			}

			$firstName = $_POST['fname'];
			$lastName = $_POST['lname'];
			$user = $_POST['username'];
			$email = $_POST['email'];
			$pass = $_POST['password'];
			$encryptPass = md5($pass);
			
			$sql = "SELECT * FROM `users` WHERE (`email` = '$email' OR `username` = '$user')";
			$checkUser = mysqli_query($connection,$sql);
			if (mysqli_num_rows($checkUser)>0) {
				$row = mysqli_fetch_assoc($checkUser);
				if ($user == $row['username']) {
					die('Username Already Exists.');
				}
				if ($email == $row['email']) {
					die("Email Already Registered. <a href='login.php'> Login Here </a> ");
				}
			}

			$insert = "INSERT INTO `users` (`id`, `fname`, `lname`, `username`, `email`, `password`) VALUES (NULL, '$firstName', '$lastName', '$user', '$email', '$encryptPass')";
			$result = mysqli_query($connection,$insert);
			if (!$result) {
				echo "Registration Failed. Re-try Again.";
				header("refresh:2; url=register.php");
			} else {
				echo "Registered.";
				header("refresh:2; url=login.php");
			}
		}
		?>

	</body>
</html>