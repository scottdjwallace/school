public class UserJob extends Thread {
	int name;
	int CPU_TIME;
	int IO_TIME;
	int bound;  // 1 = IO
				// 0 = CPU


	public UserJob(int name, int bound) { 
		this.name = name;   
		this.bound = bound;
	}


	public void run () {
		System.out.println("UserJob " + name + " is starting.");
		IO_TIME = 100;
		if (bound == 0) { // CPU BOUND
			CPU_TIME = (int)(Math.random() * 1000 + 1);
		} else { // IO BOUND
			CPU_TIME = (int)(Math.random() * 200 + 1);
		}
		while (true) {
			int using;
			try {
				CPUmonitor.mutex.acquire();
			} catch (Exception e) {}
			using = CPUmonitor.startCPUuse();
			CPUmonitor.mutex.release();
			try {
				System.out.println("UserJob " + name + " starting CPU burst from CPU " + using + " of length " + CPU_TIME);
				Thread.sleep(CPU_TIME);
			} catch (Exception e) {}
			CPUmonitor.endCPUuse(using);
			System.out.println("UserJob " + name + " starting IO burst of length " + IO_TIME);
			try {
				int t = (int)(Math.random() * 200 + 1);
				System.out.println("UserJob " + name + " is requesting access to disk sector " + t);
				DiskDrive.useTheDisk(t);
				System.out.println("UserJob " + name + " has finished accessing disk sector " + t);
			} catch (Exception e) {}
			
		}
	}
}

