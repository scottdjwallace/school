using UnityEngine;
using System.Collections;

public class musicscript : MonoBehaviour {
	private static musicscript instance = null;
	public static musicscript Instance {
		get{ return instance; }				
	}

	void Awake() {
				if (instance != null && instance != this) {
					audio.Stop();
					if (instance.audio.clip != audio.clip) {
						instance.audio.clip = audio.clip;
						instance.audio.volume = audio.volume;
						instance.audio.Play ();
					}
					Destroy(this.gameObject);
					return;
				}
				instance = this;
				audio.Play ();
				DontDestroyOnLoad (this.gameObject);
		}

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
