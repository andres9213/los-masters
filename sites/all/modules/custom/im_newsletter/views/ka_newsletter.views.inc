<?php
/*
 * @file
 */

/*
 * Implements hook_views_data()
 */
function ka_newsletter_views_data(){
	$data['ka_newsletter']['table']['group'] = t('Newsletter table');
	$data['ka_newsletter']['table']['base'] = array(
		'field' => 'id_number',
		'title' => t('Newsletter'),
		'help' => t('Contains id_number'),
		);
	$data['ka_newsletter']['id_number'] = array(
		'title' => t('id number'),
		'help' => t('Field for the id number'),
		'field' => array(
			'handler' => 'views_handler_field_numeric',
			'click sortable' => TRUE,
			),
		'filter' => array(
			'handler' => 'views_handler_field_numeric',
			),
		'sort' => array(
			'handler' => 'views_handler_sort'
			),
		);
	$data['ka_newsletter']['email'] = array(
		'title' => t('email account'),
		'help' => t('Email of the customer'),
		'field' => array(
			'handler' => 'views_handler_field',
			'click sortable' => TRUE,
			),
		'sort' => array(
			'handler' => 'views_handler_sort',
			),
		'filter' => array(
			'handler' => 'views_handler_filter_spring',
			),
		'argument' => array(
			'handler' => 'views_handler_argument_string',
			),
		);
	return $data;
}