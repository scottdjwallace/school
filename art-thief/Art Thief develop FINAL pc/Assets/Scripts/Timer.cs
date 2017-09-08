using UnityEngine;
using System.Collections;

public class Timer : MonoBehaviour {

	public GUIText timeText;
	public float timer;
	public Rect timerRect;

	public static Timer instance;

	void Awake()
	{
		instance = this;
		timer = globalproperties.LevelTime;
	}
	// Use this for initialization

	// Update is called once per frame
	void Update () {
		timer -= Time.deltaTime;
		timeText.text = "Remaining Time " + timer.ToString("0.00");
		if (timer <= 0) {
			timer = 0;
			timeText.text = "Remaining Time " + timer.ToString("0.00");
			globalproperties.LevelTime = 0;
			Application.LoadLevel("timedout");
		}
	
	}

	void OnGUI() {
		GUI.Label (timerRect, timeText.text);
	}

	public void RecordTime()
	{
		globalproperties.LevelTime = timer;
	}
}
