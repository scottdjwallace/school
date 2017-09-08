<html>
<head>
	<link href='http://fonts.googleapis.com/css?family=Source+Serif+Pro:400,700' rel='stylesheet' type='text/css'>
	<link rel="stylesheet" href="./booking_css/appArea.css"/>
	<link rel="stylesheet" href="./booking_css/appArea.css"/>
	
<body>
<div class="app_wrapper">
	<div class="app_outter_spacer"></div>
	<div class="app_inner_wrapper">
		<div class="app_container">
			<div class="top_bottom_spacer"></div>
				<!-- 
				=================================
				===	ADD YOUR APPLICATION HERE ===
				=================================
				-->	
				<?php
					$m = date('m');
   					$d = date('d');
    				$y = date('Y');
    				echo '<form action="./booking.php?m=' . $m . '&d=' . $d . '&y=' . $y . '" method="get">';
				?>
				
					<h1 class="mainApp_title">Application for Example</h1>
					<br/>
					<br/>
					<label class="app_label">Name: </label><input style="font-family:'Source Serif Pro', serif;font-size:16px;" type="text" maxlength="250" name="name_textbox" required><br/>
					<label class="app_label">Email: </label><input style="font-family:'Source Serif Pro', serif;font-size:16px;" type="text" maxlength="250" name="email_textbox" required><br/>
					<label class="app_label">Phone Number: </label><input style="font-family:'Source Serif Pro', serif;font-size:16px;" type="text" maxlength="250" name="phone_textbox" required><br/>
					<br/>
					<label class="app_question">Question 1:</label><br/>
					<textarea class="app_question_textarea" required name="q1_textbox"></textarea><br/>
					<label class="app_question">Question 2:</label><br/>
					<textarea class="app_question_textarea" required name="q2_textbox"></textarea><br/>
					<br/><br/>
					<div style="width:100%;text-align:center;">
						
						<button type="submit" class="btn">Submit and set up interview time.</button>
					</div>
				</form>
				<!-- 
				=================================
				=================================
				-->

			<div class="top_bottom_spacer"></div>
		</div>
	</div>
	<div class="app_outter_spacer"></div>

</body>
</html>