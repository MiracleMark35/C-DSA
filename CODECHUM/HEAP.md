# 1. Emergency Level
if (A.emergencyLevel != B.emergencyLevel)
    return A.emergencyLevel > B.emergencyLevel;


Rule: Lower emergency level = higher priority (Level 1 is highest).

!= checks if the two patients have different emergency levels.

A.emergencyLevel > B.emergencyLevel returns true if A has a higher number, meaning A has lower priority than B.

✅ If emergency levels are different, we don’t check anything else, because emergency level is the most important factor.

# 2. Age Category
bool A_high = (A.age < 5 || A.age > 70);
bool B_high = (B.age < 5 || B.age > 70);
if (A_high != B_high)
    return !A_high && B_high;


Rule: Patients <5 or >70 are treated before those aged 5–70.

A_high is true if patient A is high-priority by age, otherwise false. Same for B_high.

if (A_high != B_high) checks if exactly one patient is in the high-priority age group.

return !A_high && B_high;

Returns true if A is not high-priority age but B is, meaning A has lower priority.

Returns false if A is high-priority age or both are the same age category, meaning no swap needed.

This implements the “only check age if emergency levels are equal” rule.

# 3. Arrival Date
int cmp = strcmp(A.arrivalTime, B.arrivalTime);
if (cmp != 0)
    return cmp > 0;


Rule: Earlier arrival → higher priority.

strcmp compares strings lexicographically. Since dates are in "yyyy-mm-dd" format, lexicographic order matches chronological order.

If A came later than B, strcmp returns a positive number → cmp > 0 → A is lower priority.

Only applied if emergency level and age category were equal.

# 4. Patient ID (Tie-breaker)
return strcmp(A.patientID, B.patientID) > 0;


Rule: If everything else is equal, the patient with smaller patient ID is treated first.

strcmp(A.patientID, B.patientID) > 0

Returns true if A’s ID is lexicographically larger → lower priority.

Returns false if A’s ID is smaller or equal → higher or equal priority.
