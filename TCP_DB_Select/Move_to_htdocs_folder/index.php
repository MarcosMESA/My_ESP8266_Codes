<?php
				include('conexao.php');

				$proto1=$_GET['proto'];

				$sql = "SELECT Protocolo FROM protocolo WHERE Protocolo = :proto ";

				$stmt = $PDO->prepare($sql);

				$stmt->bindParam(':proto', $proto1, PDO::PARAM_STR);

				$stmt->execute();

				try {
					while ($row = $stmt->fetch()) {
    					//echo "Cod: ".$row['Num_Protocolo']." - Protocolo: ".$row['Protocolo']." - Sobre: ".$row['Sobre']." - Dia: ".$row['Hora_Criado'].";</br>\n";
    					echo "Protocolo: ".$row['Protocolo']."; \n";
					}	
				} catch (Exception $e) {
					echo "It was not possible to complete the action, due to the error: [".$e->getMessage()." ]<\br>\n";
				}
			?>
