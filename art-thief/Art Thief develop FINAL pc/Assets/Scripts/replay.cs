using UnityEngine;
using System.Collections;

public class replay : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}


	void OnGUI() {
		GUI.color = Color.cyan;
		if(GUI.Button(new Rect(100,100,60,20), "Level1")) {
			Application.LoadLevel("Level1");
		}

		if (GUI.Button (new Rect (100, 200, 60, 20), "level2")) {
			globalproperties.LevelTime = 120;
			Application.LoadLevel ("level2");
		}
		if (GUI.Button (new Rect (100, 300, 60, 20), "Level3")) {
			globalproperties.LevelTime = 120;
			Application.LoadLevel ("Level3");
		}
		if (GUI.Button (new Rect (100, 400, 60, 20), "Level4")) {
			globalproperties.LevelTime = 120;
			Application.LoadLevel ("Level4");
		}
		if (GUI.Button (new Rect (100, 500, 60, 20), "Level5")) {
			globalproperties.LevelTime = 120;
			Application.LoadLevel ("Level5");
		}
		if (GUI.Button (new Rect (100, 600, 60, 20), "Level6")) {
			globalproperties.LevelTime = 120;
			Application.LoadLevel ("Level6");
		}
		if(GUI.Button(new Rect(100,700,60,20), "menu")) {
			Application.LoadLevel("menu");
		}
				
	}
}

