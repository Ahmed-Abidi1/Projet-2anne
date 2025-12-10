-- Fix HISTORIQUE foreign key constraint to prevent CASCADE DELETE
-- This allows historique records to persist even after apartment deletion
-- 
-- IMPORTANT: Run this script in your Oracle database (SQL Developer, SQL*Plus, etc.)
-- This will remove the CASCADE DELETE behavior so historique records are preserved

-- Step 1: Drop the existing constraint with CASCADE DELETE
ALTER TABLE "SAMAR20"."HISTORIQUE" DROP CONSTRAINT "FK_APPARTEMENT";

-- Step 2: Since we want to keep historique records even after apartments are deleted,
-- we'll remove the foreign key constraint entirely. This allows historique to reference
-- apartment IDs that no longer exist in the APPARTEMENT table.
-- 
-- Note: If you prefer to keep referential integrity, you can recreate the constraint
-- with ON DELETE SET NULL (if ID_APPARTEMENT allows NULL) or ON DELETE NO ACTION,
-- but NO ACTION will prevent apartment deletion if historique records exist.
--
-- For historique/audit purposes, removing the foreign key is the best solution:
-- (Constraint is already dropped above, no need to recreate it)

-- Verify the constraint is removed:
SELECT constraint_name, constraint_type 
FROM user_constraints 
WHERE table_name = 'HISTORIQUE' AND constraint_name = 'FK_APPARTEMENT';
-- Should return no rows if successful
