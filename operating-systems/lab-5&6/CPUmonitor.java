import java.util.concurrent.Semaphore;
public class CPUmonitor {
	
	static int[] usage;
	static Semaphore mutex;
	static Semaphore CPUs;
	
	// n will be the number of cpus we have
	public static void init(int n) {
		mutex = new Semaphore(1, true);
		CPUs = new Semaphore(n, true);
		usage = new int[n];
	}
	
	public static int startCPUuse() {
		try {
			CPUs.acquire();
		} catch (Exception e) {}
		for (int i = 0; i < usage.length; i++) {
			if (usage[i] == 0) {
				usage[i] = 1;
				return i;
			}
		}
		return -1;
	}
	
	public static void endCPUuse(int i) {
		if (i >= 0) {
			usage[i] = 0;
		} else {
			// this covers the return -1 
			usage[0] = 0;
		}
		CPUs.release();
	}
}