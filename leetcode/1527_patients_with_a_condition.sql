SELECT
  patient_id,
  patient_name,
  conditions
FROM
  Patients
where
  conditions LIKE 'DIAB1%'
  OR conditions LIKE '% DIAB1%';