<?php

abstract class Synberc_MigrationMigration extends Migration {
  public function __construct() {

    parent::__construct();

    $this->team = array(
      new MigrateTeamMember('Kevin Costa', 'kcosta@berkeley.edu', t('Project Oversight')),
      new MigrateTeamMember('Anne Bonham', 'abonham@mollyduggan.com', t('Implementor')),
    );

  }
  public function getConnection($connection = 'synberc-intranet') {
	  	return Database::getConnection('default', $connection);
  }
}

