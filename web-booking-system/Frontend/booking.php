<?php
	//=============================
	//== START OF IMPORTED STUFF ==
	//=============================
	$name = $_GET['name_textbox'];
	$email = $_GET['email_textbox'];
	$phone = $_GET['phone_textbox'];

	$q1 = $_GET['q1_textbox'];
	$q2 = $_GET['q2_textbox'];

	$name = contentCheck($name);
	$email= contentCheck($email);
	$phone= contentCheck($phone);

	$q1 = contentCheck($q1);
	$q2 = contentCheck($q2);

	session_start();
	$_SESSION['app_name'] = $name;
	$_SESSION['app_email'] = $email;
	$_SESSION['app_phone'] = $phone;
	$_SESSION['app_q1'] = $q1;
	$_SESSION['app_q2'] = $q2;



	//=============================
	//=== END OF IMPORTED STUFF ===
	//=============================


	//$m = date('n');
    //$d = date('d');
    //$y = date('Y');
    $m = $_GET['m'];
    $d = $_GET['d'];
    $y = $_GET['y'];

	$f = date('m/d/Y', strtotime('last Sunday', strtotime("$m/$d/$y")));
	$arr = explode("/", $f);
	$endDay = $arr[1] + 6; //a week from the sunday
	$endOfMonth = lastDayOfTheMonth($arr[0]);
	
	$endMonth = $arr[0];
	$endYear = $arr[2];
	if($endDay > $endOfMonth){ // if the a week from sunday is a different month
		$endDay = $endDay - $endOfMonth;
		$endMonth = $endMonth	 + 1;
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
	$endOfMonth = lastDayOfTheMonth($arr[0]);
	
	$endMonth = $arr[0];
	$endYear = $arr[2];
	if($endDay > $endOfMonth){ // if the a week from sunday is a different month
		$endDay = $endDay - $endOfMonth;
		$endMonth = $endMonth	 + 1;
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
	$endOfMonth = lastDayOfTheMonth($arr[0]);
	
	$endMonth = $arr[0];
	$endYear = $arr[2];
	if($endDay > $endOfMonth){ // if the a week from sunday is a different month
		$endDay = $endDay - $endOfMonth;
		$endMonth = $endMonth	 + 1;
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
	function contentCheck($data){
		$data = trim($data);
		$data = stripslashes($data);
		$data = htmlspecialchars($data);
		return $data;
  	}
  	function lastDayOfTheMonth($para){
  		if( $para == 1 || $para == 3 || $para == 5 || $para == 7 || $para == 8 || $para == 10 || $para == 12 ){
			$result = 31;
		}else if($para == 2){
			$result = 28;
		}else{
			$result = 30;
		}
		return $result;
  	}
?>

<html>
	<head>
		<title>EXAMPLE BOOKING SYSTEM</title>
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<link href="./css/bootstrap.min.css" rel="stylesheet">
		<link href="./css/redRoom.css" rel="stylesheet">
		<link rel="shortcut icon" href="./store/asus_logo.png"></link>
		<link href="./css/navBar.css" rel="stylesheet">
		<link href="./css/footer.css" rel="stylesheet">
		
	</head>
	<body>
		
		<div style="width:100%;height:100px;"></div>
		<div class="container">
			<div class="row">
				<h1>Interview Booking</h1>
			</div>
			<div class="row">
				<h3>Things you may need to know for the interview</h3>
				<p>dteosfo of sodno ndsifo sdf diosn iosdifnisd idsio iosdfi si isd nfosdfo sifnosdfnoi dii osidnf iosdioios io i osdo[ fnsd dsifn sioi oi i soi sno oi i osoi io iois dno i io ioi nsdo inoisdfi oin in insdinf io oisnionisdnfkawnelwnk nlk klas nlan al ksnlsn noen asdnlnalksdn l lk nkl aksd.</p>
			</div>
			<div style="width:100%;height:25px;"></div>
			<div class="row">
				<h3>Schedule</h3>
				<p>Book an interview by clicking the Book Monday on the top of the columns.</p>
			</div>
			<div class="row">
				
							<a href="./cancel.php" class="btn btn-success">Cancel reservation</a>
				
			</div>
			<div style="width:100%;height:60px;"></div>
			<div class="row">
				<div class="col-md-12">
						<div class="col-sm-6 text-center">
							<?php
								$endOfMonth = lastDayOfTheMonth($previousStart_month);
								
								if( $previousStart_day == $endOfMonth ){
									$previousStart_day = 1;
									$previousStart_month++;
									if($previousStart_month == 13){
										$previousStart_month = 1;
										$previousStart_year++;
									}
								}
								echo '<a href="./booking.php?m=' . $previousStart_month . '&d=' . ($previousStart_day + 1) . '&y=' . $previousStart_year . '" class="btn btn-success navWeekButtons">';
								
									$s = "Previous: " . $previousMonthTitle_start . " " . $previousStart_day . ", " . $previousStart_year;
									$s .= " to " . $previousMonthTitle_end . " " . $previousEnd_day . ", " . $previousEnd_year;
									echo $s;
								
								echo '</a>';
							?>
						</div>
						<div class="col-sm-6 text-center">
							<?php
								$endOfMonth = lastDayOfTheMonth($nextStart_month);
								
								if( $nextStart_day == $endOfMonth ){
									$nextStart_day = 1;
									$nextStart_month++;
									if($nextStart_month == 13){
										$nextStart_month = 1;
										$nextStart_year++;
									}
								}
								echo '<a href="./booking.php?m=' . $nextStart_month . '&d=' . ($nextStart_day + 1) . '&y=' . $nextStart_year . '" class="btn btn-success navWeekButtons">';
									$s = "Next: " . $nextMonthTitle_start . " " . $nextStart_day . ", " . $nextStart_year;
									$s .= " to " . $nextMonthTitle_end . " " . $nextEnd_day . ", " . $nextEnd_year;
									echo $s;
								
								echo '</a>';
							?>
						</div>
					</div>
			</div>
			
			<div style="width:100%;height:20px;"></div>
			<div class="row">
				<div class="col-md-12">
					<table id="timeTable" style="border-bottom-style:solid;border-width:1px;border-color:grey;">
						<tr class="top_row">
							<th class="time_col">
								Times
							</th>
							<?php
								$day = $currentStart_day;
								$month = $currentStart_month;
								$year = $currentStart_year;

								$endOfMonth = lastDayOfTheMonth($month);
								
								if($day == $endOfMonth){
									$month++;
									$day = 0;
									if($month == 13){
										$month = 1;
										$year++;			
									}
									$d = 0;	
								}
								if( $day + 6 == $endOfMonth){
									$month++;
									$day = 0;
									if($month == 13){
										$month = 1;
										$year++;			
									}
									$d = 0;	
								}
								if($day + 1 == $endOfMonth){
									//next month and possibly next year
									$month++;
									$day = 1;
									if($month == 13){
										$month = 1;
										$year++;			
									}
									$d = 1;	
									echo '<th class="day_col">';
										echo '<a href="./book.php?m=' . $month . '&d=' . $d . '&y=' . $year . '">Book Monday</a>';
									echo '</th>';	
									
								}else{
									//not the next month
									$d = $day + 1;
									echo '<th class="day_col">';
										echo '<a href="./book.php?m=' . $month . '&d=' . $d . '&y=' . $year . '">Book Monday</a>';
									echo '</th>';
								}

								if($day + 2 == $endOfMonth){
									//next month and possibly next year
									$month++;
									$day = 1;
									if($month == 13){
										$month = 1;
										$year++;			
									}
									$d = 1;	
									echo '<th class="day_col">';
										echo '<a href="./book.php?m=' . $month . '&d=' . $d . '&y=' . $year . '">Book Tuesday</a>';
									echo '</th>';	
									
								}else{
									//not the next month
									$d = $day + 2;
									echo '<th class="day_col">';
										echo '<a href="./book.php?m=' . $month . '&d=' . $d . '&y=' . $year . '">Book Tuesday</a>';
									echo '</th>';
								}

								if($day + 3 == $endOfMonth){
									//next month and possibly next year
									$month++;
									$day = 1;
									if($month == 13){
										$month = 1;
										$year++;			
									}
									$d = 1;	
									echo '<th class="day_col">';
										echo '<a href="./book.php?m=' . $month . '&d=' . $d . '&y=' . $year . '">Book Wednesday</a>';
									echo '</th>';	

								}else{
									//not the next month
									$d = $day + 3;
									echo '<th class="day_col">';
										echo '<a href="./book.php?m=' . $month . '&d=' . $d . '&y=' . $year . '">Book Wednesday</a>';
									echo '</th>';
								}
								if($day + 4 == $endOfMonth){
									//next month and possibly next year
									$month++;
									$day = 1;
									if($month == 13){
										$month = 1;
										$year++;			
									}
									$d = 1;	
									echo '<th class="day_col">';
										echo '<a href="./book.php?m=' . $month . '&d=' . $d . '&y=' . $year . '">Book Thursday</a>';
									echo '</th>';

								}else{
									
									//not the next month
									$d = $day + 4;
									echo '<th class="day_col">';
										echo '<a href="./book.php?m=' . $month . '&d=' . $d . '&y=' . $year . '">Book Thursday</a>';
									echo '</th>';	
								}
								if($day + 5 == $endOfMonth){
									//next month and possibly next year
									$month++;
									$day = 1;
									if($month == 13){
										$month = 1;
										$year++;			
									}
									$d = 1;	
									echo '<th class="day_col">';
										echo '<a href="./book.php?m=' . $month . '&d=' . $d . '&y=' . $year . '">Book Friday</a>';
									echo '</th>';
								}else{
									
									//not the next month
									$d = $day + 5;
									echo '<th class="day_col">';
										echo '<a href="./book.php?m=' . $month . '&d=' . $d . '&y=' . $year . '">Book Friday</a>';
									echo '</th>';	
								}
							?>
							
								
							
							
							
						</tr>	

						<?php
							$con = mysqli_connect("localhost","YOUR_USERNAME","YOUR_PASSWORD","YOUR_DB") or die("Unable to connect");
							$arrTime = array("8:00 AM - 8:30 AM", "8:30 AM - 9:00 AM", "9:00 AM - 9:30 AM", "9:30 AM - 10:00 AM", "10:00 AM - 10:30 AM", "10:30 AM - 11:00 AM",  "11:00 AM - 11:30 AM", "11:30 PM - 12:00 PM",  "12:00 PM - 12:30 PM", "12:30 PM - 1:00 PM", "1:00 PM - 1:30 PM", "1:30 PM - 2:00 PM", "2:00 PM - 2:30 PM", "2:30 PM - 3:00 PM", "3:00 PM - 3:30 PM", "3:30 PM - 4:00 PM", "4:00 PM - 4:30 PM");
							foreach ($arrTime as $time){
								$day = $currentStart_day;
								$month = $currentStart_month;
								$year = $currentStart_year;
								echo '<tr>';
									echo '<td class="time_col">';
										echo '<p class="time_label">' . $time . '</p>';
									echo '</td>';
									
									$endOfMonth = lastDayOfTheMonth($month);
									//echo '<script>alert("End of Month:' . $endOfMonth . '");</script>';
									
									//echo '<script>alert("Day(' . $day  .' + 1 = 1 ' . ($day + 1) . '");</script>'; 
									if( $day == $endOfMonth ){
										//sunday
										$month++;
										$day = 0;
										if($month == 13){
											$month = 1;
											$year++;
											
										}
										//echo '<script>alert("' . $month . '/' . $day . '/' . $year . '");</script>';
									}
									if( $day + 6 == $endOfMonth ){
										//saturday
										$month++;
										$day = 0;
										if($month == 13){
											$month = 1;
											$year++;
											
										}
									} 
									if($day + 1 == $endOfMonth){
										//not the next month
										//echo '<script>alert("Monday1");</script>';
										//next month and possibly next year
										$month++;
										$day = 1;
										if($month == 13){
											$month = 1;
											$year++;
											
										}

										$d = 1;
										//echo '<script>alert("' . $month . '/' . $d . '/' . $year . '");</script>';
										$result = mysqli_query($con, "SELECT * FROM interview WHERE month='$month' AND day='$d' AND year='$year' AND time='$time'");
										if(mysqli_num_rows($result) >= 1){
											while($row = mysqli_fetch_array($result)){
												if($row['approved'] == 1){
													echo '<td class="day_col booked">';
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
													echo '</td>';
												}
											}
										}else{
											echo '<td class="day_col">';
											echo '</td>';
										}
									}else{

										//echo '<script>alert("Monday2");</script>';
										$d = $day + 1;
										//echo '<script>alert("1:' . $month . '/' . $d . '/' . $year . '");</script>';
										$result = mysqli_query($con, "SELECT * FROM interview WHERE month='$month' AND day='$d' AND year='$year' AND time='$time'");
										if(mysqli_num_rows($result) >= 1){
											while($row = mysqli_fetch_array($result)){
												if($row['approved'] == 1){
													echo '<td class="day_col booked">';
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
													echo '</td>';
												}
											}
										}else{
											echo '<td class="day_col">';
											echo '</td>';
										}
									}
									///end of monday
									if($day + 2 == $endOfMonth){
										//not the next month
										//echo '<script>alert("Monday1");</script>';
										//next month and possibly next year
										$month++;
										$day = 1;
										if($month == 13){
											$month = 1;
											$year++;
											
										}

										$d = 1;
										//echo '<script>alert("' . $month . '/' . $d . '/' . $year . '");</script>';
										$result = mysqli_query($con, "SELECT * FROM interview WHERE month='$month' AND day='$d' AND year='$year' AND time='$time'");
										if(mysqli_num_rows($result) >= 1){
											while($row = mysqli_fetch_array($result)){
												if($row['approved'] == 1){
													echo '<td class="day_col booked">';
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
													echo '</td>';
												}
											}
										}else{
											echo '<td class="day_col">';
											echo '</td>';
										}
									}else{

										//echo '<script>alert("Monday2");</script>';
										$d = $day + 2;
										//echo '<script>alert("1:' . $month . '/' . $d . '/' . $year . '");</script>';
										$result = mysqli_query($con, "SELECT * FROM interview WHERE month='$month' AND day='$d' AND year='$year' AND time='$time'");
										if(mysqli_num_rows($result) >= 1){
											while($row = mysqli_fetch_array($result)){
												if($row['approved'] == 1){
													echo '<td class="day_col booked">';
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
													echo '</td>';
												}
											}
										}else{
											echo '<td class="day_col">';
											echo '</td>';
										}
									}
									///end of tuesday
									if($day + 3 == $endOfMonth){
										//not the next month
										//echo '<script>alert("Monday1");</script>';
										//next month and possibly next year
										$month++;
										$day = 1;
										if($month == 13){
											$month = 1;
											$year++;
											
										}

										$d = 1;
										//echo '<script>alert("' . $month . '/' . $d . '/' . $year . '");</script>';
										$result = mysqli_query($con, "SELECT * FROM interview WHERE month='$month' AND day='$d' AND year='$year' AND time='$time'");
										if(mysqli_num_rows($result) >= 1){
											while($row = mysqli_fetch_array($result)){
												if($row['approved'] == 1){
													echo '<td class="day_col booked">';
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
													echo '</td>';
												}
											}
										}else{
											echo '<td class="day_col">';
											echo '</td>';
										}
									}else{

										//echo '<script>alert("Monday2");</script>';
										$d = $day + 3;
										//echo '<script>alert("1:' . $month . '/' . $d . '/' . $year . '");</script>';
										$result = mysqli_query($con, "SELECT * FROM interview WHERE month='$month' AND day='$d' AND year='$year' AND time='$time'");
										if(mysqli_num_rows($result) >= 1){
											while($row = mysqli_fetch_array($result)){
												if($row['approved'] == 1){
													echo '<td class="day_col booked">';
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
													echo '</td>';
												}
											}
										}else{
											echo '<td class="day_col">';
											echo '</td>';
										}
									}
									///end of wednesday
									if($day + 4 == $endOfMonth){
										//not the next month
										//echo '<script>alert("Monday1");</script>';
										//next month and possibly next year
										$month++;
										$day = 1;
										if($month == 13){
											$month = 1;
											$year++;
											
										}

										$d = 1;
										//echo '<script>alert("' . $month . '/' . $d . '/' . $year . '");</script>';
										$result = mysqli_query($con, "SELECT * FROM interview WHERE month='$month' AND day='$d' AND year='$year' AND time='$time'");
										if(mysqli_num_rows($result) >= 1){
											while($row = mysqli_fetch_array($result)){
												if($row['approved'] == 1){
													echo '<td class="day_col booked">';
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
													echo '</td>';
												}
											}
										}else{
											echo '<td class="day_col">';
											echo '</td>';
										}
									}else{

										//echo '<script>alert("Monday2");</script>';
										$d = $day + 4;
										//echo '<script>alert("1:' . $month . '/' . $d . '/' . $year . '");</script>';
										$result = mysqli_query($con, "SELECT * FROM interview WHERE month='$month' AND day='$d' AND year='$year' AND time='$time'");
										if(mysqli_num_rows($result) >= 1){
											while($row = mysqli_fetch_array($result)){
												if($row['approved'] == 1){
													echo '<td class="day_col booked">';
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
													echo '</td>';
												}
											}
										}else{
											echo '<td class="day_col">';
											echo '</td>';
										}
									}
									///end of thursday
									if($day + 5 == $endOfMonth){
										//not the next month
										//echo '<script>alert("Monday1");</script>';
										//next month and possibly next year
										$month++;
										$day = 1;
										if($month == 13){
											$month = 1;
											$year++;
											
										}

										$d = 1;
										//echo '<script>alert("' . $month . '/' . $d . '/' . $year . '");</script>';
										$result = mysqli_query($con, "SELECT * FROM interview WHERE month='$month' AND day='$d' AND year='$year' AND time='$time'");
										if(mysqli_num_rows($result) >= 1){
											while($row = mysqli_fetch_array($result)){
												if($row['approved'] == 1){
													echo '<td class="day_col booked">';
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
													echo '</td>';
												}
											}
										}else{
											echo '<td class="day_col">';
											echo '</td>';
										}
									}else{

										//echo '<script>alert("Monday2");</script>';
										$d = $day + 5;
										//echo '<script>alert("1:' . $month . '/' . $d . '/' . $year . '");</script>';
										$result = mysqli_query($con, "SELECT * FROM interview WHERE month='$month' AND day='$d' AND year='$year' AND time='$time'");
										if(mysqli_num_rows($result) >= 1){
											while($row = mysqli_fetch_array($result)){
												if($row['approved'] == 1){
													echo '<td class="day_col booked">';
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
													echo '</td>';
												}
											}
										}else{
											echo '<td class="day_col">';
											echo '</td>';
										}
									}
									///end of friday
								echo '</tr>';
							}
						?> 



					</table>
				</div>
			</div>
		</div>
		<div style="width:100%;height:100px;"></div>



		<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
		<script src="./js/bootstrap.js"></script>
	</body>
</html>