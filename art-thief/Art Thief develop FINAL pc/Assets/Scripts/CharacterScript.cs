using UnityEngine;
using System.Collections;

public class CharacterScript : MonoBehaviour {

	public float speed = 3;
	// Use this for initialization
	//void Start () {
	
	//}
	
	// Update is called once per frame

	void Update () {

		Vector3 newPos = transform.position;
		if (Input.GetKey ("right"))
		{
			newPos += Vector3.right * Time.deltaTime * speed;
			transform.position = newPos;
			//transform.Rotate(0, 0, -90);
			//this.GetComponent<CharacterController>().Move(Vector3.right * Time.deltaTime * speed);
		}
		if (Input.GetKey ("left"))
		{
			transform.position += Vector3.left * Time.deltaTime * speed;
		}
		if (Input.GetKey ("up"))
		{
			transform.position += Vector3.up * Time.deltaTime *  speed;
		}
		if (Input.GetKey ("down"))
		{
			transform.position += Vector3.down * Time.deltaTime * speed;
		}
	}





}