using UnityEngine;
using System.Collections;

public class Snowmen : MonoBehaviour {

	public int speed = 6;
	public GameObject player;
	
	public void Start () {
		player = GameObject.FindGameObjectWithTag("Player");
	}
	
	// Update is called once per frame
	void Update () {
		gameObject.transform.LookAt(player.transform.position);
		gameObject.transform.Translate (Time.deltaTime * speed * Vector3.up);
		gameObject.transform.Translate (Time.deltaTime * speed * Vector3.forward);
	}
}
