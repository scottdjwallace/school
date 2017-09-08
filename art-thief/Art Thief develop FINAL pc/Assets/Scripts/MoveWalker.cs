using UnityEngine; 
using System.Collections; 

public class MoveWalker : MonoBehaviour { 
	
	public float speed=2; // control the speed of movement in inspector 
	public GameObject target; 



	
	// Returns a vector that rotates around the x-axis by a maximum of anglesToTurn,
	// up to totalRotation. 0<=totalRotation<360. anglesToTurn>=0.
	// If y is the y-component of the resulting vector, 0<=y<360.
	/*Vector3 ClampedRotationVector(float totalRotation, float anglesToTurn) {
		if(totalRotation>180) {
			totalRotation -= 360;
		}
		float y;
		if(totalRotation>=0) {
			y = Mathf.Min(totalRotation,anglesToTurn);
		} else {
			y = Mathf.Max(totalRotation,-anglesToTurn) + 360;
		}
		return new Vector3(0,y,0);
	}
	
	void FaceTarget()
	{
		if(target != null) 
		{
			Vector3 directionToTarget = target.transform.position - transform.position;
			Quaternion rotationToFaceTarget = Quaternion.FromToRotation(transform.forward, directionToTarget);
			float anglesToTurn = TurnSpeed * Time.deltaTime;
			Vector3 rot = ClampedRotationVector(rotationToFaceTarget.eulerAngles.y, anglesToTurn);
			gameObject.transform.Rotate (rot);
		}
	}
	
	// Update is called once per frame
/*	void Update () {
		if (target != null) {
			FaceTarget();
			Vector3 movementDelta = Speed * Vector3.forward * Time.deltaTime;
			gameObject.transform.Translate(movementDelta);
		}
	}
*/



	void Start() { 
		//target = gameObject.GetComponent<SelectWaypoint>().current; 
		// access current waypoint. 
		this.transform.position = target.transform.position;
	} 
	
	void Update() { 
		// has the target changed or not 
		//if (target != gameObject.GetComponent<SelectWaypoint>().current) { 
		//	target = gameObject.GetComponent<SelectWaypoint>().current; 
		//} 
		if (target != null) {
					float distance = Vector3.Distance(this.transform.position, target.transform.position);
					if (distance < 0.03f) {
						target = target.GetComponent<WaypointNext>().next;
					}
					Vector3 dir = target.transform.position - this.transform.position;
					float angle = Mathf.Atan2 (dir.y, dir.x) * Mathf.Rad2Deg;
					this.transform.rotation = Quaternion.AngleAxis (angle, Vector3.forward);
					//	Vector3 movementDelta = speed * Vector3.forward * Time.deltaTime;
					//	gameObject.transform.Translate (movementDelta);
		
						// moves the walker toward the current waypoint 
						float step = speed * Time.deltaTime; 
						//transform.position = Vector3.MoveTowards (transform.position, 
		                                         //target.transform.position, step); 
			dir.Normalize();
			transform.position += dir * speed * Time.deltaTime;
					
				}
	} 
} 