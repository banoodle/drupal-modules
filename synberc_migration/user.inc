<?php
/**
* @file
* Migration for User data.
*/
//love it!
/**
* Migration of user_roles data. Issue: Can only get this to migrate single user/roles. There are 117 rows I've got to find a way to migrate, perhaps manually. 
*/
class SynbercUserRolesMigration extends Synberc_MigrationMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
	$this->description = t('Migrate users from the source database to users');
	$table_name = 'users_roles';
	$this->map = new MigrateSQLMap($this->machineName,
			array(
				'uid' => array(
					'type' => 'int',
					'unsigned' => TRUE,
					'not null' => TRUE,
					'alias' => 'u'
				)
			),
		MigrateDestinationTable::getKeySchema($table_name)
		);
	$query = $this->getConnection()->select('users_roles','u')
		->fields('u' , array('uid','rid'));

	$this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTable($table_name);	
		
	 // Mapped fields
    $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('rid', 'rid')
		->separator(',');	

  }

}

/**
* Migration of role data. This throws errors but works.
*/
class SynbercRolesMigration extends Synberc_MigrationMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
	$this->description = t('Migrate roles from the source database to role');
	$this->map = new MigrateSQLMap($this->machineName,
			array(
				'name' => array(
					'type' => 'varchar',
					'length' => '64',
					'not null' => TRUE,
					'alias' => 'r'
				)
			),
		MigrateDestinationRole::getKeySchema()
		);
	$query = $this->getConnection()->select('role','r')
		->fields('r' , array('name'));
	$this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));

    $this->destination = new MigrateDestinationRole();

    $this->addFieldMapping('name', 'name');

  }

}

/**
* Migration of user accounts' core fields. 
*/

class SynbercUsersMigration extends Synberc_MigrationMigration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Import core user accounts and fields');
    $this->map = new MigrateSQLMap($this->machineName,
        array('uid' => array(
                'type' => 'int',
                'unsigned' => TRUE,
                'not null' => TRUE,
                'description' => 'User ID.'
                )
             ),
        MigrateDestinationTable::getKeySchema('users')
    );
	$query = $this->getConnection()->select('users','u')
		->fields('u' , array('uid', 'mail','name', 'pass','status','created','access','login','picture','signature','signature_format','timezone','language','init'));
	
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTable('users');


    // Mapped core fields
    $this->addSimpleMappings(array('uid','mail','name', 'pass','status','created','access','login','picture','signature','signature_format','timezone','language','init'));	

 	 }
  }
  
  
/**
* Migration of user accounts' admin note custom field/table. 
*/

class SynbercUserAdminNotesMigration extends Synberc_MigrationMigration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Import custom user Admin Notes field/table');
    $this->map = new MigrateSQLMap($this->machineName,
        array('entity_id' => array(
                'type' => 'int',
                'unsigned' => TRUE,
                'not null' => TRUE,
                'description' => 'Entity ID.'
                )
             ),
     
		MigrateDestinationTable::getKeySchema('field_data_field_administrative_notes')
    );
	$query = $this->getConnection()->select('field_data_field_administrative_notes','an')
		->fields('an' , array('entity_id', 'field_administrative_notes_value','entity_type','bundle', 'revision_id','language','field_administrative_notes_format','delta'));
	
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTable('field_data_field_administrative_notes');


    // Mapped fields
    $this->addSimpleMappings(array('entity_id', 'field_administrative_notes_value','entity_type','bundle', 'revision_id','language','field_administrative_notes_format'));
	$this->addFieldMapping('delta', 'delta')
		->defaultValue('0');

 	 }
  }
  
/**
* Migration of user accounts' field_career_objective custom field/table. 
*/

class SynbercUserCareerObjectiveMigration extends Synberc_MigrationMigration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Import custom user field_career_objective field/table');
    $this->map = new MigrateSQLMap($this->machineName,
        array('entity_id' => array(
                'type' => 'int',
                'unsigned' => TRUE,
                'not null' => TRUE,
                'description' => 'Entity ID.'
                )
             ),
     
		MigrateDestinationTable::getKeySchema('field_data_field_career_objective')
    );
	$query = $this->getConnection()->select('field_data_field_career_objective','co')
		->fields('co' , array('entity_id', 'field_career_objective_value','entity_type','bundle', 'revision_id','language','deleted','delta'));
	
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTable('field_data_field_career_objective');

    // Mapped fields
    $this->addSimpleMappings(array('entity_id', 'field_career_objective_value','entity_type','bundle', 'revision_id','language',));
	$this->addFieldMapping('delta', 'delta')
		->defaultValue('0');
	$this->addFieldMapping('deleted', 'deleted')
		->defaultValue('0');

 	 }
  }
   
  
/**
* Migration of user accounts' field_cell_phone custom field/table. 
*/

class SynbercUserCellPhoneMigration extends Synberc_MigrationMigration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Import custom user field_cell_phone field/table');
    $this->map = new MigrateSQLMap($this->machineName,
        array('entity_id' => array(
                'type' => 'int',
                'unsigned' => TRUE,
                'not null' => TRUE,
                'description' => 'Entity ID.'
                )
             ),
     
		MigrateDestinationTable::getKeySchema('field_data_field_cell_phone')
    );
	$query = $this->getConnection()->select('field_data_field_cell_phone','cp')
		->fields('cp' , array('entity_id', 'field_cell_phone_value','field_cell_phone_format','entity_type','bundle', 'revision_id','language','deleted','delta'));
	
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTable('field_data_field_cell_phone');

    // Mapped fields
    $this->addSimpleMappings(array('entity_id', 'field_cell_phone_value','field_cell_phone_format','entity_type','bundle', 'revision_id','language',));
	$this->addFieldMapping('delta', 'delta')
		->defaultValue('0');
	$this->addFieldMapping('deleted', 'deleted')
		->defaultValue('0');

 	 }
  }
   
/**
* Migration of user accounts' field_country_of_origin custom field/table. 
*/

class SynbercUserCountryOriginMigration extends Synberc_MigrationMigration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Import custom user field_country_of_origin field/table');
    $this->map = new MigrateSQLMap($this->machineName,
        array('entity_id' => array(
                'type' => 'int',
                'unsigned' => TRUE,
                'not null' => TRUE,
                'description' => 'Entity ID.'
                )
             ),
     
		MigrateDestinationTable::getKeySchema('field_data_field_country_of_origin')
    );
	$query = $this->getConnection()->select('field_data_field_country_of_origin','coo')
		->fields('coo' , array('entity_id', 'field_country_of_origin_value','entity_type','bundle', 'revision_id','language','deleted','delta'));
	
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTable('field_data_field_country_of_origin');

    // Mapped fields
    $this->addSimpleMappings(array('entity_id', 'field_country_of_origin_value','entity_type','bundle', 'revision_id','language',));
	$this->addFieldMapping('delta', 'delta')
		->defaultValue('0');
	$this->addFieldMapping('deleted', 'deleted')
		->defaultValue('0');

 	 }
  }   


 
/**
* Migration of user accounts' field_discipline custom field/table. 
*/

class SynbercUserFieldDisciplineMigration extends Synberc_MigrationMigration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Import custom user field_discipline field/table');
    $this->map = new MigrateSQLMap($this->machineName,
        array('entity_id' => array(
                'type' => 'int',
                'unsigned' => TRUE,
                'not null' => TRUE,
                'description' => 'Entity ID.'
                )
             ),
     
		MigrateDestinationTable::getKeySchema('field_data_field_discipline')
    );
	$query = $this->getConnection()->select('field_data_field_discipline','fd')
		->fields('fd' , array('entity_id', 'field_discipline_value','entity_type','bundle', 'revision_id','language','deleted','delta'));
	
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTable('field_data_field_discipline');

    // Mapped fields
    $this->addSimpleMappings(array('entity_id', 'field_discipline_value','entity_type','bundle', 'revision_id','language',));
	$this->addFieldMapping('delta', 'delta')
		->defaultValue('0');
	$this->addFieldMapping('deleted', 'deleted')
		->defaultValue('0');

 	 }
  } 

/**
* Migration of user accounts' field_discipline custom field/table. 
*/

class SynbercUserSufferDisabilityMigration extends Synberc_MigrationMigration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Import custom user field_do_you_suffer_from_a_disab field/table');
    $this->map = new MigrateSQLMap($this->machineName,
        array('entity_id' => array(
                'type' => 'int',
                'unsigned' => TRUE,
                'not null' => TRUE,
                'description' => 'Entity ID.'
                )
             ),
     
		MigrateDestinationTable::getKeySchema('field_data_field_do_you_suffer_from_a_disab')
    );
	$query = $this->getConnection()->select('field_data_field_do_you_suffer_from_a_disab','sd')
		->fields('sd' , array('entity_id', 'field_do_you_suffer_from_a_disab_value','entity_type','bundle', 'revision_id','language','deleted','delta'));
	
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTable('field_data_field_do_you_suffer_from_a_disab');

    // Mapped fields
    $this->addSimpleMappings(array('entity_id', 'field_do_you_suffer_from_a_disab_value','entity_type','bundle', 'revision_id','language',));
	$this->addFieldMapping('delta', 'delta')
		->defaultValue('0');
	$this->addFieldMapping('deleted', 'deleted')
		->defaultValue('0');

 	 }
  } 