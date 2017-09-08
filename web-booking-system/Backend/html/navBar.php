<div class="navBar_wrapper">
	<p><a href="./index.php">Home</a></p>
	<?php
        $m = date('m');
        $d = date('d');
        $y = date('Y');
        echo '<p><a href="././review.php?m=' . $m . '&d=' . $d . '&y=' . $y . '">Bookings</a></p>';
    ?>
	
	<p><a href="./times.php">Times</a></p>
	<p><a href="./location.php">Locations</a></p>
	

</div>