<?php
		
		//正确返回100
		//错误返回
		//	101：帐号或者密码错误
		//
		//	120：没有获得帐号和密码
		
		
		if(isset($_GET['username'])  && isset($_GET['password'])){
				
				if($_GET['username'] == "admin" && $_GET['password'] == "123456"){
						echo "100";
				}else {
				 		echo "101";
				}
			
		}else {
		 		echo "120";
		}

?>