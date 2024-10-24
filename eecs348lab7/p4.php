<?php
// Define the number of rows and columns
$rows = name;
$columns = name;


echo "<table border='1'>";

for ($i = 1; $i <= $rows; $i++) {
    echo "<tr>"; 

    for ($j = 1; $j <= $columns; $j++) {
        echo "<td>" . $i * $j . "</td>"; 
    }
    echo "</tr>"; 
}
echo "</table>"; 
?>
