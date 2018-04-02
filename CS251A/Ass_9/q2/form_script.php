<?php

  $db = new SQLite3('db.db');
  $name=$_POST['name'];
  $address=$_POST['address'];
  $emailid=$_POST['emailid'];
  $mobileno=$_POST['mobileno'];
  $bankaccountnumber=$_POST['bankaccountnumber'];
  $password=$_POST['password'];


 // Send form data to mysql

 $IDq = $db->query("SELECT COUNT(*) as count FROM reg1 WHERE emailid = '".$emailid."'");
$IDf = $IDq->fetchArray();
//echo $IDf['count'];
if($IDf['count']){
   echo '<p>EmailID already exists</p>';
}
else{
  $sql =<<<EOF
    INSERT INTO reg1 (NAME, ADDRESS,EMAILID,MOBILENO,BANKACCOUNTNUMBER,PASSWORD)
    VALUES('$name', '$address', '$emailid', '$mobileno', '$bankaccountnumber', '$password');
EOF;




  $ret= $db->exec($sql);
  if(!$ret){
    echo $db->lastErrorMsg();
  } else{
    echo "Records created successfully";
    $query="UPDATE reg2 SET BALANCE = BALANCE - 1000 WHERE BANKACCOUNTNUMBER = '".$bankaccountnumber."'";
    $ret= $db->exec($query);

    }


 }
 ?>
