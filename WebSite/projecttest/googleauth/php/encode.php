<?php
		require_once 'GoogleAuthenticator.php';
		$ga = new PHPGangsta_GoogleAuthenticator();
		
		$secret = $ga->createSecret();
		$lketc = "lketc";
		$lkpool = "lkpool";
		$account = "topseten";
		//$qrCodeUrl = $ga->getQRCodeGoogleUrl('lk pool', $secret);
		//rawurlencode("$lketc:$lkpool:$account")  用于记录标识
		$otpauth = 'otpauth://totp/'.rawurlencode("$lketc:$lkpool:$account").'?secret='.rawurlencode($secret).'&lketc='.rawurlencode($lketc);
		//echo $qrCodeUrl."#".$secret;
		echo $otpauth."#".$secret;
?>