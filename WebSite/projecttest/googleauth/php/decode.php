<?php
		if(isset($_POST['SecretKey']) && isset($_POST['VerifyCode'])){
				require_once 'GoogleAuthenticator.php';
				
				$ga = new PHPGangsta_GoogleAuthenticator();
		
				$secret = $_POST['SecretKey'];
		
				//$oneCode = $ga->getCode($secret);
				$oneCode = $_POST['VerifyCode'];
				
				$checkResult = $ga->verifyCode($secret, $oneCode, 2);    // 2 = 2*30sec clock tolerance
				
				if ($checkResult) {
				    echo 'OK';
				} else {
				    echo 'FAILED';
				}
		}else {
		 		echo "hi,boy,this is a scary place.";
		}
?>