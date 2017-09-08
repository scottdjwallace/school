
public class DiskDrive {
	
	static int currentTrack;
	
	public DiskDrive() {
		currentTrack = 0;
	}
	
	public static synchronized void useTheDisk(int track) {
		int timeNeeded = 1 + Math.abs(currentTrack - track);
		System.out.println("The disk head needs to travel from " + currentTrack + 
							" to " + (timeNeeded - 1) +
							".  This will take " + timeNeeded + " time.");
		try {
			Thread.sleep(timeNeeded);
		} catch (Exception e) {}
		currentTrack = track;
	}

}

