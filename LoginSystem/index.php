<?php
	session_start();
	if (isset($_SESSION['loggedin']) && $_SESSION['loggedin'] == 'yes') {
		echo "Welcome ".$_SESSION["name"];
		echo "<br/>";
		echo $_SESSION["username"];
		echo "<br/>";
		echo "<a href='logout.php'> <button> Logout </button> </a> ";
	} else echo "<a href='login.php'> Login. </a>";
	
?>
