<?php
// practice4.php
    $size = (int)($_POST['size'] ?? 0);

    if ($size < 1) {
        echo "Invalid number. <a href='practice4.html'>Back</a>";
    exit;
}
?>
<!DOCTYPE html>
<html>
<body>
<h1>Multiplication Table (1 to <?php echo $size; ?>)</h1>

<table border="1" cellpadding="5">
<tr>
<th>x</th>
<?php
// column indexes
    for ($c = 1; $c <= $size; $c++) {
        echo "<th>$c</th>";
}
?>
</tr>

<?php
// each row
    for ($r = 1; $r <= $size; $r++) {
        echo "<tr>";
// row index
    echo "<th>$r</th>";
// cells
    for ($c = 1; $c <= $size; $c++) {
        echo "<td>" . ($r * $c) . "</td>";
}
    echo "</tr>";
}
?>
</table>

<p><a href="practice4.html">Back</a></p>
</body>
</html>