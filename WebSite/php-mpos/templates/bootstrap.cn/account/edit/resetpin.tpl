<form action="{$smarty.server.SCRIPT_NAME}" method="post" role="form">
  <input type="hidden" name="page" value="{$smarty.request.page|escape}">
  <input type="hidden" name="action" value="{$smarty.request.action|escape}">
  <input type="hidden" name="do" value="genPin">
  <input type="hidden" name="ctoken" value="{$CTOKEN|escape|default:""}" />
  <div class="col-lg-6">
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-lock fa-fw"></i> 重置4 数字取币PIN码
      </div>
      <div class="panel-body">
        <div class="row">
          <div class="col-lg-12">
            <div class="form-group">
              <label>当面登陆密码</label>
              <input class="form-control" type="password" name="currentPassword">
            </div>
          </div>
        </div>
      </div>
      <div class="panel-footer">
        <input type="submit" class="btn btn-success btn-sm" value="确认重置PIN码">
      </div>
    </div>
  </div>
</form>