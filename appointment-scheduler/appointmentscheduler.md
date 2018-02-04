# Appointment Scheduler

### Problem
Schedule any subset of maximum number of appointments from a given list of appointments, with start and end times, such that there is no overlap.

### Description
Give a list of appointments, schedule a maximum number of appointments such that there is no overlap among them.

```
class Appointment:
    def __init__(subject, beginTime, endTime):
        self._subject = subject
        self._start = beginTime
        self._end = endTime

    def overlaps(self, another_appt):
        # Assume this method is implemented,
        # or implement if possible (time)


def appointment_scheduler(appointments_list):
    # implement here
    pass

```

### Example

For visual purposes, each appointment will be represented as a tuple of all three member objects.
i.e (subject, start, end)

#### Input 1
[ (A, 1030, 1100),
  (B, 1100, 1200),
  (C, 1200, 1230)
]

#### Output 1
[ A, B, C ]

#### Input 2
[ (A, 1030, 1100),
  (B, 1045, 1200),
  (C, 1200, 1230)
]

#### Output 2
[ A, C ] or [ B, C]

### Extension 1
Implement the missing 'overlaps' function inside 'Appointment' class. 

### Extension 2
Given a list of appointments, what is the maximum number of rooms that need to be reserved if all the appointments occur?

#### Input 1
[ (A, 1030, 1100),
  (B, 1100, 1200),
  (C, 1200, 1230)
]

#### Output 1
1

#### Input 2
[ (A, 1030, 1100),
  (B, 1045, 1200),
  (C, 1200, 1230)
]

#### Output 2
2
