using UnityEngine;
using System.Collections;

public class Throw : MonoBehaviour {
	
	public GameObject projectile;
	public float force;
	
	void Update () {
		if (Input.GetKeyDown (KeyCode.F)) {
			GameObject p = Instantiate (projectile, transform.position + transform.forward, transform.rotation) as GameObject;
			p.rigidbody.AddForce (transform.forward * force);
		}
	}
	
}

