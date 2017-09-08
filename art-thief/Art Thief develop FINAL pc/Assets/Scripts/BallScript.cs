using UnityEngine;
using System.Collections;

public class BallScript : MonoBehaviour {

	public float force = 10;
	public float angle = 45;
	public float torque = 10;

	public AudioClip smash;

	Vector2 ballForce = new Vector2();

	// Use this for initialization
	void Start () {
		ballForce.x = force* Mathf.Cos(Mathf.Deg2Rad * angle);
		ballForce.y = force* Mathf.Sin(Mathf.Deg2Rad * angle);
	}
	

	void OnMouseDown()
	{
		this.rigidbody2D.AddForce(ballForce);
		this.rigidbody2D.AddTorque(torque);
	}

	void OnCollisionEnter2D(Collision2D other)
	{
		if (other.gameObject.name != "Background")
		{
		    if (this.transform.position.y > -3.0f)
			{
			     audio.PlayOneShot(smash);
			}
		}
	}


}
