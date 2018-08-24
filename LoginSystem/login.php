<?php
	session_start();
	if (isset($_SESSION['loggedin']) && ($_SESSION['loggedin'] == 'yes')) {
	 	header('location: index.php');
	 } 
?>
<!DOCTYPE html>
<html>
<head>
	<title>Login Page</title>
</head>
<body>
	<div style="width: 25%;">
	<form action="login.php" method="post">
		<fieldset>
			<legend>Login Details</legend>
			<table>
				<tr>
					<td align="right">Username:</td>
					<td><input type="text" name="username" placeholder=" Enter Your Username"></td>
				</tr>
				<tr>
					<td colspan="2" align="right"> <span id="errorUsername"></span> </td>
				</tr>
				<tr>
					<td align="right">Password:</td>
					<td> <input type="password" name="password" placeholder=" ***********" required="required"> </td>
				</tr>
				<tr>
					<td colspan="2" align="right"> <input type="submit" value="Login" name="submit"></td>
				</tr>
			</table>
			Not registered yet? <a href="register.php"> Register Here. </a>
		</fieldset>
	</form>
</div>
	
	<script type="text/javascript" src="custom.js"></script>
	<?php
		if (isset($_POST['submit'])){
		$conn = mysqli_connect("localhost","root","","loginsystem");
		if (!$conn) {
			die ('Database connection failed.');
		}

		$user = $_POST['username'];
		$pass = $_POST['password'];
		$encryptPass = md5($pass);
		// echo "$encryptPass";
		// echo "<br/>";
		
		$sql = "SELECT * FROM `users` WHERE `username` = '$user'";
	
		$checkUser = mysqli_query($conn,$sql);

		$row = mysqli_fetch_assoc($checkUser);
		$savedPass = ($row['password']);
		// echo($savedPass);
		if (!$savedPass) {
			echo("Username Not Registered.");
			echo "<br/>";
			echo ("<a href='register.php'>Register here.</a>");
			echo("<br/>");
		}elseif ($savedPass == $encryptPass) {
			echo "Login Sucess"." !!";
			$_SESSION['loggedin'] = 'yes';
			$_SESSION["name"] = ($row['fname']);
			$_SESSION["username"] = $user;
			header("refresh:1; url=index.php");
		} else {
			die ("Password didn't match. Try Again.");
		}
	}
	?>
</body>
</html>