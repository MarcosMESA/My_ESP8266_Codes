<?php
	try {
		$HOST = "localhost";
		$BANCO = "mesinha_proto";
		$USER = "root";
		$SENHA = "";

		$PDO = new PDO("mysql:host=" . $HOST . ";dbname=" . $BANCO . ";charset=utf8", $USER, $SENHA);
	} catch (PDOException $erro) {
		echo "Erro de conexao: " . $erro->getMessage();
		//echo "conexao erro";
	}
?>