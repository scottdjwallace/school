/*
 * Engine.h
 *
 *  Created on: Mar 28, 2015
 *      Author: 7cm5_000
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include <stdexcept>
#include <vector>
#include "ics_files/ICS_VCalendar.h"

class Engine {
public:
	static ICS_Day generateFreeEventsOfDay(vector<ICS_Day> dangerDays){
		cout << "        Engine::generateFreeEventsOfDay()" << endl;
		int numPeople = dangerDays.size();

		if (numPeople == 0) {
			throw runtime_error("empty days");
		}
		vector<ICS_Day> days;
		//cout << "number of people = " << numPeople << endl;

		ICS_Date date = dangerDays[0].getDate();
		//cout << "        date = " << date << endl;
		for (unsigned int i = 0; i < dangerDays.size(); i += 1){
			if (dangerDays[i].size() > 0){
				days.push_back(dangerDays[i]);
			}
		}
		numPeople = days.size();
		ICS_Day commonDay(date);
		//cout << "the days do match" << endl;

		int* pEventIndex = new int[numPeople];
		int* pEventCount = new int[numPeople];

		bool noEvents = true;

		for (int i = 0; i < numPeople; i += 1){
			pEventIndex[i] = -1;
			pEventCount[i] = days[i].size();
			if (pEventCount[i] > 0){
				noEvents = false;
			}
		}

		if (noEvents){
			//cout << "no events. therefore, whole day is free" << endl;
			ICS_Date cLatestEndTime(date);
			cLatestEndTime.setHour(23);
			cLatestEndTime.setMinute(59);
			ICS_VEvent freeEvent(date, cLatestEndTime);
			commonDay.add(freeEvent);
		} else {
			// get the earliest block: i.e. find earliest start time
			int furthestPerson = -1;
			////cout << "    1) finding earliest start time." << endl;
			ICS_Date earliestStartTime(date + 1);
			ICS_Date cLatestEndTime(date + 1);
			for (int person = 0; person < numPeople; person += 1){
				if (days[person].size() > 0 && days[person][0].getStartTime() < earliestStartTime){
					furthestPerson = person;
					earliestStartTime = days[person][0].getStartTime();
					cLatestEndTime = days[person][0].getEndTime();
				}
			}

			//////cout<< "        earliestStartTime = ";
			//cout << earliestStartTime << endl;

			//cout << "        creating earliest event" << endl;
			ICS_VEvent earliestEvent(date, earliestStartTime);
			commonDay.add(earliestEvent);
			//cout << "        earliest event created:" << endl;
			//cout << "        ";
			//cout << earliestEvent << endl;

			// we have moved to the start of a persons events
			pEventIndex[furthestPerson] = 0;

			ICS_Date furthestTime = days[furthestPerson][(pEventIndex[furthestPerson])].getEndTime();

			int i = 0;
			//cout << "    2) finding other events." << endl;
			while (!atEndOfDays(numPeople, pEventIndex, pEventCount)){
				if (i > 50) break;
				i += 1;
				//cout << "        furthestPerson = " << furthestPerson << ", furthestTime = ";
				//cout << furthestTime << endl;
				bool canMove = false;

				for (int person = 0; person < numPeople; person += 1){
					if (person == furthestPerson){
						if (pEventIndex[person] < pEventCount[person] - 1){
							if (days[person][(pEventIndex[person] + 1)].getStartTime() <= furthestTime){
								canMove = true;
								pEventIndex[person] += 1;
								furthestTime = days[person][(pEventIndex[person])].getEndTime();
								furthestPerson = person;
								break;
							}
						}
						continue;
					}
					if (pEventIndex[person] >= pEventCount[person]) continue;

					// person is not the furthest person
					bool personStarted = pEventIndex[person] >= 0;
					if (!personStarted){
						// person has not started;
						if (days[person][0].getStartTime() <= furthestTime){
							canMove = true;
							pEventIndex[person] = 0;
							if (days[person][(pEventIndex[person])].getEndTime() > furthestTime){
								furthestTime = days[person][(pEventIndex[person])].getEndTime();
								furthestPerson = person;
							}
							break;
						}
					} else {
						// person has started
						if (pEventIndex[person] < pEventCount[person] - 1){
							int tryStartIndex = pEventIndex[person] + 1;
							if (days[person][tryStartIndex].getStartTime() <= furthestTime){
								canMove = true;
								pEventIndex[person] += 1;
								if (days[person][tryStartIndex].getEndTime() > furthestTime){
									furthestTime = days[person][(pEventIndex[person])].getEndTime();
									furthestPerson = person;
								}
								break;
							}
						} else {
							pEventIndex[person] += 1;
						}
					}
				}

				//cout << "        moved = " << (canMove ? "true" : "false") << endl;
				//cout << "        furthest = " << furthestPerson << endl;
				//cout << "        furthestTime = " << furthestTime << endl;
				if (!canMove){

					// create an event;
					ICS_Date earliestNextStartTime(date);
					earliestNextStartTime.setHour(23);
					earliestNextStartTime.setMinute(59);
					int earliestStartPerson = -1;
					for (int person = 0; person < numPeople; person += 1){
						//cout << "            person " << person << ", eventIndex = " << pEventIndex[person] << endl;
						if (pEventIndex[person] >= pEventCount[person] - 1) {
							//cout << "            cannot move ahead" << endl;
							continue; // cannot move ahead
						}
						if (person == furthestPerson){
							if (pEventIndex[person] < pEventCount[person] - 1){
								if (days[person][(pEventIndex[person] + 1)].getStartTime() < earliestNextStartTime){
									earliestStartPerson = person;
									earliestNextStartTime = days[person][(pEventIndex[person] + 1)].getStartTime();
								}
							}
						} else {
							bool personStarted = pEventIndex[person] >= 0;
							if (!personStarted){
							// person has not started;
								if (days[person][0].getStartTime() < furthestTime){
									earliestStartPerson = person;
									earliestNextStartTime = days[person][(pEventIndex[person]) + 1].getStartTime();
								}
							} else if (pEventIndex[person] < pEventCount[person] - 1){
								if (days[person][(pEventIndex[person]) + 1].getStartTime() < earliestNextStartTime){
									earliestStartPerson = person;
									earliestNextStartTime = days[person][(pEventIndex[person]) + 1].getStartTime();
								}
							}
						}
						//cout << "        earliestStartTime = ";
						//cout << earliestNextStartTime << endl;
					}

					ICS_VEvent newFreeTime(furthestTime, earliestNextStartTime);
					//cout << "        event created" << endl;
					//cout << "        ";
					//cout << newFreeTime << endl;
					commonDay.add(newFreeTime);

					if (earliestStartPerson != -1){
						furthestPerson = earliestStartPerson;
					}
					pEventIndex[furthestPerson] += 1;
					if (pEventIndex[furthestPerson] < pEventCount[furthestPerson]){
						furthestTime = days[furthestPerson][(pEventIndex[furthestPerson])].getEndTime();
					}
				}

				/*
				if (!canMove){
					for (int person = 0; person < numPeople; person += 1){
						if (person == furthestPerson) continue;

						if (!pAtEndTime[person]){ // person is at start time
							int pIndex = pEventIndex[person];
							if (days[person][pIndex].getStartTime() < furthestTime){
								// go to endTime
								pAtEndTime[person] = true;
								if (days[person][pIndex].getEndTime() > furthestTime){
									furthestTime = days[person][pIndex].getEndTime();
									furthestPerson = person;
									break;
								}
							}
						} else {

						}
					}
				} else { // cant move: create an event

				}
				*/
			}
			delete[] pEventIndex;
			delete[] pEventCount;
		}

		cout << "        group free time: " << endl;
		for (int i = 0; i < commonDay.size(); i += 1){
			cout << "            ";
			cout << commonDay[i] << endl;
		}

		return commonDay;
	}
private:
	bool static atEndOfDays(int numPeople, int* personsEventIndex, int* personsEventCount){
		for (int i = 0; i < numPeople; i += 1){
			if (personsEventIndex[i] < personsEventCount[i]){
				return false;
			}
		}
		return true;
	}

public:
	static ICS_VCalendar generateFreeTimeCalendar(vector<ICS_VCalendar> calendars, ICS_Date startDate, ICS_Date endDate) {
		if (calendars.size() == 0){
			throw runtime_error("empty calendars vector");
		}
		cout << "Engine::generateCommonDay() started:" << endl;
		cout << "start date = " << startDate << endl;
		cout << "end date = " << endDate << endl;
		cout << endl;
		vector<vector<ICS_Day>> individualCalendarDays;
		ICS_VCalendar commonCalendar;

		commonCalendar.setTimezone(calendars[0].getTimezone());
		commonCalendar.setName("The Groups Common Free Time Calendar");
		commonCalendar.setCalscale(calendars[0].getCalscale());
		commonCalendar.setMethod("PUBLISH");

		cout << "    generating VEvents based on the events and their rules for each calendar in calendars." << endl;
		int numDates = startDate.dayDifference(endDate);
		cout << "    numDates = " << numDates << endl;
		for (int date = 0; date <= numDates; date += 1){
			cout << "        event generation date = " << date << endl;
			vector<ICS_Day> sameDayOfAllCalendars;

			for (unsigned int person = 0; person < calendars.size(); person += 1){
				ICS_Date currentDate = startDate + date;
				ICS_VCalendar currentCal = calendars[person];
				ICS_Day currentDay = currentCal.getEventsOn(currentDate);
				sameDayOfAllCalendars.push_back(currentDay);
			}
			individualCalendarDays.push_back(sameDayOfAllCalendars);
		}
		cout << endl;

		cout << "    generating common ICS_Days" << endl;
		for (unsigned int day = 0; day < individualCalendarDays.size(); day += 1){
			try{
				ICS_Day peoplesICSDays = generateFreeEventsOfDay(individualCalendarDays[day]);
				for (unsigned int i = 0; i < peoplesICSDays.size(); i += 1){
					commonCalendar.addVEvent(peoplesICSDays[i]);
				}
			} catch (runtime_error& e){
				cout << "    Error: " << e.what() << endl;
			}
		}

		return commonCalendar;
	}
};


#endif /* ENGINE_H_ */
