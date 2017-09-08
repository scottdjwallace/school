using UnityEngine;
using System.Collections;

public class Melt : MonoBehaviour {

	public void OnCollisionEnter(Collision collision) {
		if (collision.gameObject.name == "SnowMan(Clone)") {
			Destroy (collision.gameObject);
		}
		Destroy (gameObject);
	}
}
