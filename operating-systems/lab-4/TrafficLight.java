
public class TrafficLight extends Thread{
	
	TrafficLight(){
		Synch.timeSim.threadStart();
	}
	
	public static int Q = 100;
	public static int T = 200;
	
	public void run ()
	{
		while (Synch.running)
		{
			try {
				Synch.mutex.acquire();
			} catch (Exception e){}
			for (int i = 0; i < Synch.eastbound_waiting; i++)
			{
				Synch.eastSem.release();
			}
			Synch.traffic_light = "Green Eastbound";
			Synch.mutex.release();
			
			Synch.timeSim.doSleep(T);
			Synch.traffic_light = "RED";
			Synch.timeSim.doSleep(Q);
			
			try {
				Synch.mutex.acquire();
			} catch (Exception e){}
			for (int i = 0; i < Synch.westbound_waiting; i++)
			{
				Synch.westSem.release();
			}
			Synch.traffic_light = "Green Westbound";
			Synch.mutex.release();
			
			Synch.timeSim.doSleep(T);
			Synch.traffic_light = "RED";
			Synch.timeSim.doSleep(Q);
		}
		Synch.timeSim.threadEnd();
	}
	

}
