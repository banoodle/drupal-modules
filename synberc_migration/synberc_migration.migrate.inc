<?php

/**
* Implements hook_migrate_api().
*/
function synberc_migration_migrate_api() {
	return array(
	'api' => 2,
	'migrations' => array(
		'SynbercUserRoles' => array('class_name' => 'SynbercUserRolesMigration',),
		'SynbercRoles' => array('class_name' => 'SynbercRolesMigration',),
		'SynbercUsers' => array('class_name' => 'SynbercUsersMigration',),
		'SynbercUserAdminNotes' => array('class_name' => 'SynbercUserAdminNotesMigration',),
		'SynbercUserCareerObjective' => array('class_name' => 'SynbercUserCareerObjectiveMigration',),
		'SynbercUserCellPhone' => array('class_name' => 'SynbercUserCellPhoneMigration',),
		'SynbercUserCountryOrigin' => array('class_name' => 'SynbercUserCountryOriginMigration',),
		'SynbercUserFieldDiscipline' => array('class_name' => 'SynbercUserFieldDisciplineMigration',),
		'SynbercUserSufferDisability' => array('class_name' => 'SynbercUserSufferDisabilityMigration',),
			),
	);
}