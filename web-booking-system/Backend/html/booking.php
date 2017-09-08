<div style="width:100%;height:60px;"></div>
			<div class="row">
				<div class="col-md-12">
						<div class="col-sm-6 text-center">
							<?php
								if( $previousStart_month == 1 || $previousStart_month == 3 || $previousStart_month == 5 || $previousStart_month == 7 || $previousStart_month == 8 || $previousStart_month == 10 || $previousStart_month == 12 ){
									$endOfMonth = 31;
								}else if($previousStart_month == 2){
									$endOfMonth = 28;
								}else{
									$endOfMonth = 30;
								}
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
								if( $nextStart_month == 1 || $nextStart_month == 3 || $nextStart_month == 5 || $nextStart_month == 7 || $nextStart_month == 8 || $nextStart_month == 10 || $nextStart_month == 12 ){
									$endOfMonth = 31;
								}else if($nextStart_month == 2){
									$endOfMonth = 28;
								}else{
									$endOfMonth = 30;
								}
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


								if( $month == 1 || $month == 3 || $month == 5 || $month == 7 || $month == 8 || $month == 10 || $month == 12 ){
									$endOfMonth = 31;
								}else if($month == 2){
									$endOfMonth = 28;
								}else{
									$endOfMonth = 30;
								}
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
							$con = mysqli_connect("localhost","YOUR_USERNAME","YOUR_PASSWORD","YOUR_DATABASE") or die("Unable to connect");
							$arrTime = array("8:00 AM - 8:30 AM", "8:30 AM - 9:00 AM", "9:00 AM - 9:30 AM", "9:30 AM - 10:00 AM", "10:00 AM - 10:30 AM", "10:30 AM - 11:00 AM",  "11:00 AM - 11:30 AM", "11:30 PM - 12:00 PM",  "12:00 PM - 12:30 PM", "12:30 PM - 1:00 PM", "1:00 PM - 1:30 PM", "1:30 PM - 2:00 PM", "2:00 PM - 2:30 PM", "2:30 PM - 3:00 PM", "3:00 PM - 3:30 PM", "3:30 PM - 4:00 PM", "4:00 PM - 4:30 PM");
							foreach ($arrTime as $time){
								$day = $currentStart_day;
								$month = $currentStart_month;
								$year = $currentStart_year;
								echo '<tr>';
									echo '<td class="time_col">';
										echo '<p class="time_label">' . $time . '</p>';
									echo '</td>';
									if( $month == 1 || $month == 3 || $month == 5 || $month == 7 || $month == 8 || $month == 10 || $month == 12 ){
										$endOfMonth = 31;
									}else if($month == 2){
										$endOfMonth = 28;
									}else{
										$endOfMonth = 30;
									}
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
														$row['eventName'];
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
														$row['eventName'];
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
														$row['eventName'];
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
														$row['eventName'];
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
														$row['eventName'];
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
														$row['eventName'];
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
														$row['eventName'];
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
														$row['eventName'];
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
														$row['eventName'];
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
														$row['eventName'];
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
														$row['eventName'];
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
														$row['eventName'];
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
														$row['eventName'];
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
														$row['eventName'];
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
														$row['eventName'];
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
														$row['eventName'];
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
														$row['eventName'];
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
														$row['eventName'];
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
														$row['eventName'];
													echo '</td>';
												}else{
													echo '<td class="day_col pending">';
														$row['eventName'];
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