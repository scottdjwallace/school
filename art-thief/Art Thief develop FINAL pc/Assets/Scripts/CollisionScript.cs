using UnityEngine;
using System.Collections;

public class CollisionScript : MonoBehaviour {

	public GameObject particles;

	void OnCollisionEnter2D(Collision2D other ) 
	{
		
		if (other.gameObject.name == "Background")
		{
			GameObject ps = Instantiate(particles,transform.position, transform.rotation) as GameObject;
			ps.renderer.sortingOrder = 2;

			GameObject thanks = GameObject.Find("Thanks");
			thanks.renderer.enabled = true;

			Destroy(this.gameObject);
		}

	}

}
