<?php
  //$m = date('n');
    //$d = date('d');
    //$y = date('Y');
    $m = $_GET['m'];
    $d = $_GET['d'];
    $y = $_GET['y'];

  $f = date('m/d/Y', strtotime('last Sunday', strtotime("$m/$d/$y")));
  $arr = explode("/", $f);
  $endDay = $arr[1] + 6; //a week from the sunday
  if( $arr[0] == 1 || $arr[0] == 3 || $arr[0] == 5 || $arr[0] == 7 || $arr[0] == 8 || $arr[0] == 10 || $arr[0] == 12 ){
    $endOfMonth = 31;
  }else if($arr[0] == 2){
    $endOfMonth = 28;
  }else{
    $endOfMonth = 30;
  }
  $endMonth = $arr[0];
  $endYear = $arr[2];
  if($endDay > $endOfMonth){ // if the a week from sunday is a different month
    $endDay = $endDay - $endOfMonth;
    $endMonth = $endMonth  + 1;
    if($endOfMonth == 13){
      $endMonth = 1;
      $endYear = $endYear + 1;
    }
  }
  $currentStart_month = $arr[0];
  $currentStart_day = $arr[1];
  $currentStart_year = $arr[2];

  $currentEnd_month = $endMonth;
  $currentEnd_day = $endDay;
  $currentEnd_year = $endYear;
  
  //get the previous
  //minus 7
  //may go under zero
  $m = $_GET['m'];
    $d = $_GET['d'];
    $y = $_GET['y'];

  $d = $d - 7;
  if($d < 0 ){
    $d = 31 + $d;
    $m = $m - 1;
    if($m == 0){
      $m = 12;
      $y = $y - 1;
    }
  }


  $f = date('m/d/Y', strtotime('last Sunday', strtotime("$m/$d/$y")));
  $arr = explode("/", $f);
  $endDay = $arr[1] + 6; //a week from the sunday
  if( $arr[0] == 1 || $arr[0] == 3 || $arr[0] == 5 || $arr[0] == 7 || $arr[0] == 8 || $arr[0] == 10 || $arr[0] == 12 ){
    $endOfMonth = 31;
  }else if($arr[0] == 2){
    $endOfMonth = 28;
  }else{
    $endOfMonth = 30;
  }
  $endMonth = $arr[0];
  $endYear = $arr[2];
  if($endDay > $endOfMonth){ // if the a week from sunday is a different month
    $endDay = $endDay - $endOfMonth;
    $endMonth = $endMonth  + 1;
    if($endOfMonth == 13){
      $endMonth = 1;
      $endYear = $endYear + 1;
    }
  }

  $previousStart_month = $arr[0];
  $previousStart_day = $arr[1];
  $previousStart_year = $arr[2];

  $previousEnd_month = $endMonth;
  $previousEnd_day = $endDay;
  $previousEnd_year = $endYear;

  $m = $_GET['m'];
    $d = $_GET['d'];
    $y = $_GET['y'];

    $d = $d + 7;
    $e = 30;
    if($m == 1 || $m == 3 || $m == 5 || $m == 7 || $m == 8 || $m == 10 || $m == 12){
      $e = 31;
    }else if($m == 2){
      $e = 28;
    }else{
      $e = 30;
    }
    if($d > $e){
      $d = $d - $e;
      $m = $m + 1;
      if($m == 13){
        $m = 1;
        $y = $y + 1;
      }
    }

  $f = date('m/d/Y', strtotime('last Sunday', strtotime("$m/$d/$y")));
  $arr = explode("/", $f);
  $endDay = $arr[1] + 6; //a week from the sunday
  if( $arr[0] == 1 || $arr[0] == 3 || $arr[0] == 5 || $arr[0] == 7 || $arr[0] == 8 || $arr[0] == 10 || $arr[0] == 12 ){
    $endOfMonth = 31;
  }else if($arr[0] == 2){
    $endOfMonth = 28;
  }else{
    $endOfMonth = 30;
  }
  $endMonth = $arr[0];
  $endYear = $arr[2];
  if($endDay > $endOfMonth){ // if the a week from sunday is a different month
    $endDay = $endDay - $endOfMonth;
    $endMonth = $endMonth  + 1;
    if($endOfMonth == 13){
      $endMonth = 1;
      $endYear = $endYear + 1;
    }
  }

  $nextStart_month = $arr[0];
  $nextStart_day = $arr[1];
  $nextStart_year = $arr[2];

  $nextEnd_month = $endMonth;
  $nextEnd_day = $endDay;
  $nextEnd_year = $endYear;

  $nextMonthTitle_start = whatMonth($nextStart_month);
  $nextMonthTitle_end = whatMonth($nextEnd_month);

  $currentMonthTitle_start = whatMonth($currentStart_month);
  $currentMonthTitle_end = whatMonth($currentEnd_month);

  $previousMonthTitle_start = whatMonth($previousStart_month);
  $previousMonthTitle_end = whatMonth($previousEnd_month);

  function whatMonth($m){
    $s = "";
    if($m == 1){
      $s = "January";
    }else if($m == 2){
      $s = "February";
    }else if($m == 3){
      $s = "March";
    }else if($m == 4){
      $s = "April";
    }else if($m == 5){
      $s = "May";
    }else if($m == 6){
      $s = "June";
    }else if($m == 7){
      $s = "July";
    }else if($m == 8){
      $s = "August";
    }else if($m == 9){
      $s = "September";
    }else if($m == 10){
      $s = "October";
    }else if($m == 11){
      $s = "November";
    }else{
      $s = "December";
    }
    return $s;
  }
?>


<html>
	<head>
		<!-- This page, people review the applications -->
	</head>	
	<body>
		<?php
			include_once('./html/navBar.php');
		?>
		<div class="outter_shell">
          <div class="app_wrapper">
              
              <div class="app_inner">
                  <div class="app_spacer"></div>

                  <?php
                        $code = "";
                        $month = "";
                        $day = "";
                        $time = "";
                        $eventName = "";
                        $org = "";
                        $name = "";
                        $email = "";
                        $phoneNum = "";
                        $eventDes = "";
                        $ppl = "";
                        $comments = "";

                        $con = mysqli_connect("localhost","YOUR_USERNAME","YOUR_PASSWORD","YOUR_DB") or die("Unable to connect");
                        $result = mysqli_query($con, "SELECT * FROM interview WHERE approved=0") or die("Unable to pull info off red room");
                        while($row = mysqli_fetch_array($result)){
                            $code = $row['code'];
                            $month = $row['month'];
                            $day = $row['day'];
                            $year = $row['year'];
                            $time = $row['time'];
                            $eventName = $row['eventName'];
                            $org = $row['org'];
                            $name = $row['name'];
                            $email = $row['email'];
                            $phoneNum = $row['phoneNum'];
                            $eventDes = $row['eventDes'];
                            $ppl = $row['ppl'];
                            $comments = $row['comments'];

                        }
                         echo '<label class="app_label">Date:' . $month . ' ' . $day . ', ' . $year . ' @ ' . $time . '</label><br/>';
                        echo '<label class="app_label">Name:' . $name . '</label><br/>';
                        echo '<label class="app_label">Org:' . $org . '</label><br/>';
                        echo '<label class="app_label">Email:<a href="mailto:' . $email . '">' . $email . '</a></label><br/>';
                        echo '<label class="app_label">Phone:' . $phoneNum . '</label><br/>';
                        echo '<br/><br/>';
                        echo '<label class="app_label">Event:' . $eventName . '</label><br/>';
                        echo '<label class="app_label">Description:</label><br/>';
                        echo '<label class="app_label">' . $eventDes . '</label><br/>';
                        echo '<label class="app_label">People:' . $ppl . '</label><br/>';
                        echo '<br/><br/>';
                        echo '<label class="app_label">Comments</label><br/>';
                        echo '<label class="app_label">' . $comments . '</label><br/>';

                        echo '<form action="./actions/accept.php" method="post">';
                            echo '<input type="text" hidden name="code_textbox" value="' . $code . '"/>';
                            echo '<button type="submit" class="btn btn-success">Accept</button>'; 
                        echo '</form>';
                        echo '<form action="./actions/denied.php" method="post">';
                            echo '<input type="text" hidden name="code_textbox" value="' . $code . '"/>';
                            echo '<button type="submit" class="btn btn-danger">Decline</button>'; 
                        echo '</form>';

                  ?>

                  
                  <div class="app_spacer"></div>
              </div>
              
          </div>
      </div>
      
      <?php
          include_once('./html/booking.php');
      ?>

	</body>
</html>