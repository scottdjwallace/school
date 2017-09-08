using UnityEngine;
using System.Collections;

public class Spawn : MonoBehaviour {

	float last_time;
	public GameObject enemy;
	public int round = 1;
	
	public void Update () {
		if (last_time + 3.0 < Time.time) {
			Rigidbody enemyInstance;
			enemyInstance = Instantiate (enemy, transform.position, transform.rotation) as Rigidbody;
			last_time = Time.time;
		}
	}

}
