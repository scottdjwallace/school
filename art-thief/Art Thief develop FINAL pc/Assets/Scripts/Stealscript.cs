using UnityEngine;
using System.Collections;

public class Stealscript : MonoBehaviour {
	public bool isStealing;
	private int steals = 0;
	public string level;
	public AudioClip steal;
	Animator animator; 
	// Use this for initialization
	void Start () {
			animator = GetComponent<Animator>();
	}
	
	// Update is called once per frame
	void Update () {
		
	}
	void OnTriggerStay2D(Collider2D other) {
				if (other.gameObject.name == "Painting-A") {
						Vector3 dir = other.transform.position - this.transform.position;
						float angle = Mathf.Atan2 (dir.y, dir.x) * Mathf.Rad2Deg;
						this.transform.rotation = Quaternion.AngleAxis (angle, Vector3.forward);
						SpriteRenderer sr = other.gameObject.GetComponent<SpriteRenderer> ();
						if (Input.GetKeyUp (KeyCode.Space)) {
								steals += 1;
								animator.SetBool ("isStealing", true);
								audio.PlayOneShot(steal);
								StartCoroutine (WaitAndDestroy (0.04f, other.gameObject));
						}
				} else if (other.gameObject.name == "Painting-B") {
						Vector3 dir = other.transform.position - this.transform.position;
						float angle = Mathf.Atan2 (dir.y, dir.x) * Mathf.Rad2Deg;
						this.transform.rotation = Quaternion.AngleAxis (angle, Vector3.forward);
						SpriteRenderer sr = other.gameObject.GetComponent<SpriteRenderer> ();
						if (Input.GetKeyUp (KeyCode.Space)) {
								steals += 1;
								animator.SetBool ("isStealing", true);
								audio.PlayOneShot(steal);
								StartCoroutine (WaitAndDestroy (0.04f, other.gameObject));
						}
				} else if (other.gameObject.name == "Sculpture") {
						Vector3 dir = other.transform.position - this.transform.position;
						float angle = Mathf.Atan2 (dir.y, dir.x) * Mathf.Rad2Deg;
						this.transform.rotation = Quaternion.AngleAxis (angle, Vector3.forward);
						SpriteRenderer sr = other.gameObject.GetComponent<SpriteRenderer> ();
						if (Input.GetKeyUp (KeyCode.Space)) {
								steals += 1;
								animator.SetBool ("isStealing", true);
								audio.PlayOneShot(steal);
								StartCoroutine (WaitAndDestroy (0.04f, other.gameObject));
						}
				} 
	}
	
	void OnTriggerEnter2D(Collider2D other) {
		if (other.gameObject.name == "camview90") {
			Timer.instance.RecordTime();
			Application.LoadLevel("caught");		
		}
		if (other.gameObject.name == "camview60") {
			Timer.instance.RecordTime();
			Application.LoadLevel("caught");		
		}
		if (other.gameObject.name == "camview30") {
			Timer.instance.RecordTime();
			Application.LoadLevel("caught");		
		}
		if (other.gameObject.name == "security") {
			Timer.instance.RecordTime();
			Application.LoadLevel("caught");		
		}

		if (other.gameObject.name == "Door B"){
			Debug.Log(steals);
			if (steals == 3){
				Timer.instance.RecordTime();
				globalproperties.currentlvl = level;
				Application.LoadLevel(level);
			}
		}
	}

	IEnumerator WaitAndDestroy(float time, GameObject go) {
		yield return new WaitForSeconds(time);
		animator.SetBool("isStealing", false);
		Destroy (go);
	}
}