<?php
 /*
  * @file
  */

 /* 
  * Implements hook_views_data()
  */

 function im_newsletter_views_data(){
  $data['im_newsletter']['table']['group'] = t('Newsletter Table');
  $data['im_newsletter']['table']['base'] = array(
    'field' => 'id_number',
    'title' => t('Newsletter'),
    'help' => t('Contains id_number'),
    );
  $data['im_newsletter']['id_number'] = array(
    'title' => t('id_number'),
    'help' => t('Field for the id_number'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
      ),
    'filter' => array(
      'handler' => 'views_handler_field_numeric',
      ),
    'sort' =>array(
      'handler' => 'views_handler_sort',
      ),
    );
  $data['im_newsletter']['name'] = array(
    'title' => t('Name'),
    'help' => t('Name of the customer'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
      ),
    'sort' => array(
      'handler' => 'views_handler_sort',
      ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      ),
    'argument' => array(
      'handler' => 'views_handler_argument_string'
      ),
    );
  $data['im_newsletter']['email'] = array(
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