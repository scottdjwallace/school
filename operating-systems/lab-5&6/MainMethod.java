public class MainMethod {
  public static void main (String argv[]) {
	  System.out.println("The simulation of the computer system is starting");

	  UserJob U;
	  int n = 3; // number of CPUs
	  int uj = 20; // number of UserJobs
	  CPUmonitor.init(n); // initialize the monitor to n CPUs
	  double r;
	  for (int i = 0; i < uj; i++) {
		  r = Math.random(); 
		  if (r > 0.5) {
			  // IO Bound
			  U = new UserJob(i, 1);
		  } else {
			  // CPU Bound
			  U = new UserJob(i, 0);
		  }
		  U.start();
	  }
	
  }  // end of "main"
}  // end of "MainMethod"