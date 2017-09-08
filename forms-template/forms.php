<?php

// Login Credentials
$username="USERNAME";
$password="PASSWORD";
$database="TABLE_NAME";
// Connect to Datebase
mysql_connect(localhost,$username,$password);
// Select Database table
@mysql_select_db($database) or die( "Unable to select database");

// SQL QUERY
$query="SQL COMMAND HERE";
mysql_query($query1);

// PRINT
echo "Hello World!";

// RETRIEVE DATA FROM FORM
$name = $_POST['HTML_ELEMENT_NAME'];

// SQL INJECTION TEST V1
$name = contentCheck($name);
function contentCheck($data){
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}

// SQL INJECTION TEST V2
$stmt = $dbConnection->prepare('SELECT * FROM employees WHERE name = ?');
$stmt->bind_param('s', $name);
$stmt->execute();
$result = $stmt->get_result();
while ($row = $result->fetch_assoc()) {
    // do something with $row
}

// CLOSE CONNECTION
mysql_close();
?>
