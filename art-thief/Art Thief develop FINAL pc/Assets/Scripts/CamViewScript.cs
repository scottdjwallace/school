using UnityEngine;
using System.Collections;

public class CamViewScript : MonoBehaviour {
	public float spinSpeed = 1f;
	public float direction = 1;
	public float minAngle = 30;
	public float maxAngle = 330;

	public bool towardsMin = true;

	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
		/*
		float angle = 360 - transform.rotation.eulerAngles.z;
		if (transform.rotation.eulerAngles.z > maxAngle) {
			direction = 1;
		} 
		else if (angle < minAngle) {
			direction = -1;

		}
		*/
		//this.transform.rotation *= Quaternion.Euler(new Vector3(0, 0, spinSpeed * Time.deltaTime * direction));

		Quaternion minQuat = Quaternion.Euler(new Vector3(0, 0, minAngle));
		Quaternion maxQuat = Quaternion.Euler(new Vector3(0, 0, maxAngle));
		Quaternion newRotation = Quaternion.identity;

		if (towardsMin) 
		{
			newRotation = Quaternion.RotateTowards (this.transform.rotation, minQuat, spinSpeed);
			float angle = Quaternion.Angle (newRotation, minQuat);
			if (angle < 0.1f) 
			{
				towardsMin = false;
			}
		} 
		else 
		{
			newRotation = Quaternion.RotateTowards (this.transform.rotation, maxQuat, spinSpeed);
			float angle = Quaternion.Angle (newRotation, maxQuat);
			if (angle < 0.1f) 
			{
				towardsMin = true;
			}
		}

		this.transform.rotation = newRotation;
	}
}	
