using UnityEngine;
using System.Collections;

public class BrushScript : MonoBehaviour {

	public float velocity = 1.0f;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKey(KeyCode.D) || Input.GetKey(KeyCode.RightArrow))
		{
			this.transform.position += Vector3.right * velocity * Time.deltaTime;
		}
		if (Input.GetKey(KeyCode.A) || Input.GetKey(KeyCode.LeftArrow))
		{
			this.transform.position -= Vector3.right * velocity * Time.deltaTime;
		}

	}

	void OnTriggerEnter2D(Collider2D other)
	{
		if (other.gameObject.name != "Background")
		{
			SpriteRenderer sr = other.gameObject.GetComponent<SpriteRenderer>();
			sr.color = Color.gray;
		}

	}

	void OnTriggerExit2D(Collider2D other)
	{
		if (other.gameObject.name != "Background")
		{
			SpriteRenderer sr = other.gameObject.GetComponent<SpriteRenderer>();
			sr.color = Color.white;
		}
	}


}
