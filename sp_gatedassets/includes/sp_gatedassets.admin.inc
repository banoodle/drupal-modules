<?php

/**
 * @file
 * Administrative page callbacks for the Marketo MA module.
 */

/**
 * Builds and returns the Marketo settings form.
 */
function sp_gatedassets_admin_settings_form($form, &$form_state) {
  $form['sp_gatedassets']['sp_gatedassets_marketo_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Marketo Account ID'),
    '#default_value' => variable_get('sp_gatedassets_marketo_id', ''),
    '#required' => TRUE,
  );
  $form['sp_gatedassets']['sp_gatedassets_marketo_form'] = array(
    '#type' => 'textfield',
    '#title' => t('Marketo Form ID'),
    '#default_value' => variable_get('sp_gatedassets_marketo_form', ''),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}
