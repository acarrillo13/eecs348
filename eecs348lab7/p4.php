<?php
// Define the number of rows and columns
$rows = name;
$columns = name;

// Start the HTML table with borders for clarity
echo "<table border='1'>";
// Generate rows of the table
for ($i = 1; $i <= $rows; $i++) {
    echo "<tr>"; // Start a new row
    // Generate columns within the row
    for ($j = 1; $j <= $columns; $j++) {
        echo "<td>" . $i * $j . "</td>"; // Calculate and display the product
    }
    echo "</tr>"; // End the row
}
echo "</table>"; // Close the table
?>
